#ifndef FORMCONDITIONS_H
#define FORMCONDITIONS_H

#include <QWidget>
#include <QListWidgetItem>

#include "searchthread.h"

namespace Ui {
class FormConditions;
}

class MainWindow;

Q_DECLARE_METATYPE(Condition)

class FormConditions : public QWidget
{
    Q_OBJECT

public:
    explicit FormConditions(QWidget *parent = nullptr);
    ~FormConditions();

    QVector<Condition> getConditions() const;
    void updateSensitivity();
    int getIndex(int idx) const;

    QListWidgetItem *lockItem(QListWidgetItem *item);
    void setItemCondition(QListWidget *list, QListWidgetItem *item, Condition *cond);
    void editCondition(QListWidgetItem *item);

signals:
    void changed();

public slots:
    void on_buttonRemoveAll_clicked();
    void on_buttonRemove_clicked();
    void on_buttonDisable_clicked();
    void on_buttonEdit_clicked();
    void on_buttonAddFilter_clicked();

    void on_listConditionsFull_customContextMenuRequested(const QPoint &pos);
    void on_listConditionsFull_itemDoubleClicked(QListWidgetItem *item);
    void on_listConditionsFull_itemSelectionChanged();

    void conditionsAdd();
    void conditionsEdit();
    void conditionsCut();
    void conditionsCopy();
    int conditionsPaste(bool countonly = false);
    void conditionsDelete();

    void addItemCondition(QListWidgetItem *item, Condition cond, int modified = 1);

private slots:
    void on_listConditionsFull_indexesMoved(const QModelIndexList &indexes);

protected:
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    MainWindow *parent;
    Ui::FormConditions *ui;
};

#endif // FORMCONDITIONS_H
