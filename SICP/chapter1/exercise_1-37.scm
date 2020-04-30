(define (cont-frac-iter n d k val)
  (if (= k 0) 
	  val
	  (cont-frac-iter n d (- k 1) (/ (n k) (+ (d k) val)))))

(define (cont-frac-recur n d k max)
  (if (= k max)
	  0
	  (/ (n k) (+ (d k) (cont-frac-recur n d (+ k 1) max)))))

(define (cont-frac n d k)
  (cont-frac-iter n d k 0))

(cont-frac (lambda (i) 1.0)
           (lambda (i) 1.0)
           100)

(define (cont-frac n d k)
  (cont-frac-recur n d 1 k))

(cont-frac (lambda (i) 1.0)
           (lambda (i) 1.0)
           100)
