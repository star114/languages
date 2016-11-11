#lang racket

;set as an unordered list
(define (element-of-set? x set)
 (cond ((null? set) false)
      ((equal? x (car set)) true)
     (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
 (if (element-of-set? x set)
    set
   (cons x set)))

;quiz1

(define (intersect-set set1 set2)
  (cond ((or (null? set1)) (null? set2) '())
        ((element-of-set? (car set2) set1) (adjoin-set (car set2) (intersect-set set1 (cdr set2))))
        (else (intersect-set set1 (cdr set2)))
        )
  )

(define (union-set set1 set2)
  (if (null? set2) set1 (union-set (adjoin-set (car set2) set1) (cdr set2)))
  )

;> (intersect-set (list 1 2 4 6) (list 3 2 5 6))
;'(2 6)
;> (union-set (list 1 2 4 6) (list 3 2 5 6))
;'(5 3 1 2 4 6)

;set as an ordered-list
(define (element-of-set2? x set)
  (cond ((null? set) false)
        ((= x (car set)) true)
        ((< x (car set)) false)
        (else (element-of-set2? x (cdr set)))))

; quiz2 - do not use element-of-set
(define (intersect-set2 set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((= (car set1) (car set2)) (cons (car set1) (intersect-set2 (cdr set1) (cdr set2))))
        ((< (car set1) (car set2)) (intersect-set2 (cdr set1) set2))
        ((> (car set1) (car set2)) (intersect-set2 set1 (cdr set2)))
        )
)

;> (intersect-set2 (list 1 2 3 4 5) (list 1 2 4 8 16)) 
;'(1 2 4)


;binary-tree
(define (entry tree) (car tree))
(define (left-branch tree) (cadr tree))
(define (right-branch tree) (caddr tree))
(define (make-tree entry left right) (list entry left right))


; quiz3
(define (element-of-tree? x tree)
  (cond ((null? tree) #f)
        ((= x (entry tree)) #t)
        ((< x (entry tree)) (element-of-tree? x (left-branch tree)))
        (else (element-of-tree? x (right-branch tree)))
        )
)

;(define t1 (make-tree 5 (make-tree 3 (make-tree 1 '() '()) '()) (make-tree 6 '() (make-tree 7 '() '()))))
;> (element-of-tree? 5 t1)
;#t
;> (element-of-tree? 3 t1)
;#t
;> (element-of-tree? 4 t1)
;#f



;homework1 
(define (insert-tree x tree)
  (cond ((null? tree) (make-tree x '() '()))
        ((= x (entry tree)) tree)
        ((< x (entry tree)) (make-tree (entry tree) (insert-tree x (left-branch tree)) (right-branch tree)))
        (else (make-tree (entry tree) (left-branch tree) (insert-tree x (right-branch tree))))
        )
)

(define t1 (make-tree 5 (make-tree 3 (make-tree 1 '() '()) '()) (make-tree 6 '() (make-tree 7 '() '()))))
(insert-tree 3 t1)
;'(5 (3 (1 () ()) ()) (6 () (7 () ())))
(insert-tree 4 t1)
;'(5 (3 (1 () ()) (4 () ())) (6 () (7 () ())))
(insert-tree 8 t1)
;'(5 (3 (1 () ()) ()) (6 () (7 () (8 () ()))))
(insert-tree 0 t1)
;'(5 (3 (1 (0 () ()) ()) ()) (6 () (7 () ())))
(insert-tree 6 (insert-tree 5 (insert-tree 4 (insert-tree 3 (insert-tree 2 (insert-tree 1 '()))))))
;'(1 () (2 () (3 () (4 () (5 () (6 () ()))))))



;homework2
;(define (list->tree elements)  
;  (define (partial-tree elts n)
;    (if (= n 0)
;        (cons '() elts)
;        (let ((left-size (quotient (- n 1) 2)))
;          (let ((left-result (partial-tree elts left-size)))
;            (let ((left-tree (car left-result))
;                  (non-left-elts (cdr left-result))
;                  (right-size (- n (+ left-size 1))))
;              (let ((this-entry <??>)
;                    (right-result <??>))
;                (let ((right-tree <??>)
;                      (remaining-elts <??>))
;                  (cons <??> remaining-elts))))))))
;  (car (partial-tree elements (length elements))))