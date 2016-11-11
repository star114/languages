#lang racket

;--- huffman trees ---
; procedures for leaf
(define (make-leaf symbol weight) (list 'leaf symbol weight))
(define (leaf? object) (eq? (car object) 'leaf))
(define (symbol-leaf x) (cadr x))
(define (weight-leaf x) (caddr x))

; procedures for general tree
(define (symbols tree)
  (if (leaf? tree)
      (list (symbol-leaf tree))
      (caddr tree)))

(define (weight tree)
  (if (leaf? tree)
      (weight-leaf tree)
      (cadddr tree)))

(define (make-code-tree left right)
  (list left right (append (symbols left) (symbols right)) (+ (weight left) (weight right))))



;--- QUIZ 1: DECODING ---
(define (left-branch tree) (car tree))
(define (right-branch tree) (cadr tree))

(define (choose-branch bit branch)
  (cond ((= bit 0) (left-branch branch))
        ((= bit 1) (right-branch branch))
        (else (error "bad bit -- CHOOSE-BRANCH" bit))))

; input: bits, huffman tree
; output: symbols
(define (decode bits tree)
  (define (decode-1 bits current-branch)
    (if (null? bits)
        '()
        (let ((next-branch (choose-branch (car bits) current-branch)))
          (if (leaf? next-branch)
              (cons (symbol-leaf next-branch)
                    (decode-1 (cdr bits) tree))
              (decode-1 (cdr bits) next-branch)))))
  (decode-1 bits tree))

; check result
(define sample-tree
  (make-code-tree (make-leaf 'A 4)
                  (make-code-tree
                   (make-leaf 'B 2)
                   (make-code-tree (make-leaf 'D 1)
                                   (make-leaf 'C 1)))))
(define sample-code '(0 1 1 0 0 1 0 1 0 1 1 1 0))
;(decode sample-code sample-tree)
; '(A D A B B C A)



;--- QUIZ 2: SETS OF WEIGHTED ELEMENTS ---
; represent a set of leaves and trees as a list arranged in increasing order of weight
; input: leafq, ordered list of leafs
; output: ordered list of leafs including the input leaf
(define (adjoin-set x set)
  (cond ((null? set) (list x))
        ((< (weight x) (weight (car set))) (cons x set))
        (else (cons (car set)
                    (adjoin-set x (cdr set))))))

(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set (make-leaf (car pair) (cadr pair))
                    (make-leaf-set (cdr pairs))))))

; check result
(define sample-set (list (list 'A 4) (list 'D 1) (list 'C 1) (list 'B 2)))
;(make-leaf-set sample-set)
; '((leaf C 1) (leaf D 1) (leaf B 2) (leaf A 4))



;--- HOMEWORK 1: ENCODING ---
; input: symbol, huffman tree
; output: code
;(define (encode-symbol symbol tree)
;  ( <??> ))

(define (encode message tree)
  (if (null? message)
      '()
      (append (encode-symbol (car message) tree)
              (encode (cdr message) tree))))

; check result
(define sample-message '(A D A B B C A))
(encode sample-message sample-tree)
; '(0 1 1 0 0 1 0 1 0 1 1 1 0)



;--- HOMEWORK 2: GENERATE HUFFMAN TREE ---
; input: ordered leafs
; output: huffman tree
;(define (successive-merge ordered-leafs)
;  ( <??> ))
 
(define (generate-huffman-tree pairs)
  (successive-merge (make-leaf-set pairs)))

; check result
(generate-huffman-tree sample-set)
; '((leaf A 4) ((leaf B 2) ((leaf C 1) (leaf D 1) (C D) 2) (B C D) 4) (A B C D) 8)

; check final result
(define get-a-job-pairs '((A 2) (NA 16) (BOOM  1) (SHA 3) (GET 2) (YIP 9) (JOB 2) (WAH 1)))
(define get-a-job-tree (generate-huffman-tree get-a-job-pairs))
(define get-a-job '(GET A JOB
                        SHA NA NA NA NA NA NA NA NA
                        GET A JOB SHA NA NA NA NA NA NA NA NA
                        WAH YIP YIP YIP YIP YIP YIP YIP YIP YIP
                        SHA BOOM))
; (encode get-a-job get-a-job-tree)
; '(1 1 1 1 1 1 1 0 0 1 1 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 0 0 1 1 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 1 0 1 1)
(length (encode get-a-job get-a-job-tree))
; 84