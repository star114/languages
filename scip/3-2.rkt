#lang racket
;(define x (cons (list 1 2) (list 3 4)))
;(define input (list (list 1 (list 2 3)) (list 4 5)))
;(define input2 (list (list 1 (list 2 (list 3 6))) (list 4 (list (list 5 9) (list 7 8)))))

(define (accumulate op initial sequence)
	(if (null? sequence)
	    initial
	    (op (car sequence)
		 (accumulate op initial (cdr sequence)))))

(define (count-leaves t)
	(accumulate + 0 (map (lambda x (if (list? (car x)) (count-leaves (car x)) 1)) t)))

;(count-leaves x)
;(count-leaves input)
;(count-leaves input2)
