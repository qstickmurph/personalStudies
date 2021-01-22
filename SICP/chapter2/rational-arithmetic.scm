(define (add-rat x y)
  (make-rat (+ (numer x) (denom y)
			   (numer y) (denom x))
			(* (denom x) (denom y))))

(define (sub-rat x y)
  (make-rat (- (numer x) (denom y)
			   (numer y) (denom x))
			(* (denom x) (denom y))))

(define (mul-rat x y)
  (make-rat (* (numer x) (numer y))
			(* (denom x) (denom y))))

(define (div-rat x y)
  (make-rat (/ (numer x) (numer y))
			(/ (denom x) (denom y))))

(define (equal-rat? x y)
  (= (* (numer x) (denom y)) (* (numer y) (denom x))))

(define (make-rat x y)
  (let ((g (gcd x y))
    (cons (/ x g) (/ y g)))))

(define (numer x)
  (car x))

(define (denom x)
  (cdr x))

