#lang racket
; quiz 1
;(define equal-list? equal?)
(define (equal-list? x y)
  (cond
    [(and (not (pair? x)) (not (pair? y))) (eq? x y)]
    [(and (pair? x) (pair? y)) (and (equal-list? (car x) (car y)) (equal-list? (cdr x) (cdr y)))]
    [else #f]
    )
  )
(equal-list? '(1 2 3 (4 5) 6) '(1 2 3 (4 5) 6))
(equal-list? '(1 2 3 (4 5) 6) '(1 2 3 (4 5 7) 6))

; 미분
(define (variable? x) (symbol? x))
(define (same-variable? v1 v2)
    (and (variable? v1) (variable? v2) (eq? v1 v2)))
(define (sum? x) (and (pair? x) (eq? (car x) '+)))
(define (addend s) (cadr s))
(define (augend s) (caddr s))
(define (product? x) (and (pair? x) (eq? (car x) '*)))
(define (multiplier p) (cadr p))
(define (multiplicand p) (caddr p))
(define (=number? exp num) (and (number? exp) (= exp num)))
(define (make-sum a1 a2)
    (cond ((=number? a1 0) a2)
          ((=number? a2 0) a1)
          ((and (number? a1) (number? a2))
           (+ a1 a2))
          (else (list '+ a1 a2))))
(define (make-product m1 m2)
    (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list '* m1 m2))))

(define (exponentiation? exp) (and (pair? exp) (eq? (car exp) '**)))
(exponentiation? '(** x 2))

(define (base exp) (cadr exp))
(base '(** x 2))

(define (exponent exp) (caddr exp))
(exponent '(** x 2))

(define (make-exponentiation base exp)
  (cond ((=number? base 0) 0)
        ((=number? base 1) 1)
        ((=number? exp 0) 1)
        ((=number? exp 1) base)
        (else (list '** base exp))
        )
  )
(make-exponentiation 'x 2)

(define (deriv exp var)
    (cond ((number? exp) 0)
          ((variable? exp) (if (same-variable? exp var) 1 0))
          ((sum? exp) (make-sum (deriv (addend exp) var) (deriv (augend exp) var)))
          ((product? exp) (make-sum (make-product (multiplier exp) (deriv (multiplicand exp) var)) (make-product (deriv (multiplier exp) var) (multiplicand exp))))
          ((exponentiation? exp) (make-product (exponent exp) (make-exponentiation (base exp) (- (exponent exp) 1))))
          (else
           (error "unknown expression type: DERIV" exp))))

; test
(deriv '(+ x 3) 'x)
(deriv '(* x y) 'x)
(deriv '(* (* x y) (+ x 3)) 'x)
(deriv '(+ (+ (** x 5) (* (** x 3) y)) 1) 'x)

