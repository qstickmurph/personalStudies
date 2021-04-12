import os as os
import sys as sys
import re as re

def main():
    # Test argv
    if not (len(sys.argv) == 5 or len(sys.argv) == 7):
        print('Usage <Data Directory> <Template File> <MM-DD-YYYY> [<Starting Delimeter> <Ending Delimeter>]')
        return
    if len(sys.argv) == 5:
       frontDelim = '<<'
       backDelim = '>>'
    else:
       frontDelim = sys.argv[5]
       backDelim = sys.argv[6]
    
    # Test if date arg is correct
    dateString = sys.argv[3]
    if not re.match(r'\d{2}-\d{2}-\d{4}', dateString):
        print(f'Date "{ dateString }" is not a valid date. (MM-DD-YYYY expected)')
        return

    try:
        # Open template file
        templateFile = open(sys.argv[2])

        # Open data directory 
        dataDir = os.listdir(sys.argv[1])

        # Loop over all data files and apply them to the template
        for filename in dataDir:
            templateFile.seek(0)
            # Initialize variables
            dataDict = {}
            
            dataDict['datestamp'] = dateString
            # Load data from data file
            with open(os.path.join(sys.argv[1], filename)) as data:
                lines = data.readlines()
                dataDict['dept_code'] = lines[0].split(' ')[0]
                dataDict['dept_name'] = ' '.join(lines[0].split(' ')[1:])[:-1]
                dataDict['course_name'] = lines[1][:-1]
                dataDict['course_start'] = lines[2].split(' ')[1]
                dataDict['course_end'] = lines[2].split(' ')[2][:-1]
                dataDict['credit_hours'] = lines[3][:-1]
                dataDict['num_students'] = lines[4][:-1]
                dataDict['course_num'] = re.search(r'\d+', filename).group(0)
            
            # Write data to new file
            with open(os.path.join(sys.argv[4], filename.split('.')[0] + '.warn'), 'w+') as newFile:
                for line in templateFile.readlines():
                    for key in dataDict.keys():
                        line = line.replace(frontDelim + key + backDelim, dataDict[key])
                    newFile.write(line)

    except EnvironmentError as e:
        print(e)

    templateFile.close()

if __name__ == '__main__':
    main()
