#include <QPushButton>
#include "position.hpp"
#include "piece.hpp"
#include <memory>

class Case : public QPushButton {
    Q_OBJECT

public:
    Case(const Position& pos, std::unique_ptr<Piece> piece, QWidget* parent = nullptr); 
    //connect(this, &QPushButton::clicked, this, &CaseButton::onClicked);
    Case() = default;

    void setPiece(std::unique_ptr<Piece> newPiece);

signals:
    void caseClicked(const Position& pos);

private slots:
    void onClicked() {
        emit caseClicked(position);
    }
private:
    void updateButtonAppearance();

    Position position;
    std::unique_ptr<Piece> piece;
};