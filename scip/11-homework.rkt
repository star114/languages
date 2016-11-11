#lang racket


;;; Scheme code for Twenty-One Simulator [PS2 Fall '90]

(define (twenty-one player-strategy house-strategy)
  (let ((house-initial-hand (make-new-hand (deal))))
    (let ((player-hand
           (play-hand player-strategy
                      (make-new-hand (deal))
                      (hand-up-card house-initial-hand))))
      (display "End of PLAYER turn")(newline)
      (cond ((> (hand-total player-hand) 21)
            (display "HOUSE wins!")(newline)
            0)                                ; ``bust'': player loses
            (else
            (let ((house-hand 
                   (play-hand house-strategy
                              house-initial-hand
                              (hand-up-card player-hand))))
              (display "End of HOUSE turn")(newline)
              (cond ((> (hand-total house-hand) 21)
                     (display "PLAYER wins!")(newline)
                     1)                      ; ``bust'': house loses
                    ((> (hand-total player-hand)
                        (hand-total house-hand))
                     (display (hand-total player-hand))(display " vs ") (display (hand-total house-hand))(newline)
                     (display "PLAYER wins!")(newline)
                     1)                      ; house loses
                    (else
                     (display "HOUSE wins!")(newline)
                     0))))))))           ; player loses

(define (play-hand strategy my-hand opponent-up-card)
  (cond ((> (hand-total my-hand) 21) (display "BUST!")(newline) my-hand) ; I lose... give up
        ((strategy my-hand opponent-up-card) ; hit?
         (play-hand strategy
                    (hand-add-card my-hand (deal))
                    opponent-up-card))
        (else my-hand)))                ; stay


(define (deal) (let ((rand (+ 1 (random 13))))
                     (let ((next (if (> rand 10) 10 rand)))
                       (display next) (display " dealt")(newline) next)))

(define (make-new-hand first-card)
  (make-hand first-card first-card))

(define (make-hand up-card total)
  (cons up-card total))

(define (hand-up-card hand)
  (car hand))

(define (hand-total hand)
  (cdr hand))

(define (hand-add-card hand new-card)
  (make-hand (hand-up-card hand)
             (+ new-card (hand-total hand))))


; for manual game play

(define (hit? your-hand opponent-up-card)
  (newline)
  (display "Opponent up card ")
  (display opponent-up-card)
  (newline)
  (display "Your Total: ")
  (display (hand-total your-hand))
  (newline)
  (display "Hit? ")
  (newline)
  (user-says-y?))


(define (user-says-y?) (let ((read (read-line)))
                         (cond ((string=? read "y") true)
                              ((string=? read "n") false)
                              ((display "y or n?")
                               (newline)(user-says-y?)))))


;;(twenty-one hit? hit?)

(define (stop-at x) (lambda (your-hand opponent-up-card) (cond ((>= (hand-total your-hand) x) true)
                                                               (else false))))
;(twenty-one hit? (stop-at 16))

;(twenty-one (stop-at 15) (stop-at 16))

(define (test-strategy x y times)
  (if (= times 0) 0 (+ (twenty-one x y) (test-strategy x y (- times 1)))))
;(test-strategy (stop-at 16) (stop-at 11) 1000)

(define (my-own-st)
  (define (get-avg deck) 6.538461538461538)
  (lambda (your-hand opponent-up-card) (cond ((>= (- 21 (hand-total your-hand)) (get-avg opponent-up-card)) true)
                                             (else false))))
(test-strategy  (my-own-st) (stop-at 16) 10000)