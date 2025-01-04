#pragma once

#include <QWidget>

#include <QCheckBox>
#include <QSpinBox>

#include <QVector>

class CommonPredictorFiltersWidget : public QWidget
{
public:
  CommonPredictorFiltersWidget(QWidget* parent = nullptr);
  virtual ~CommonPredictorFiltersWidget();

  int getMinHpIv() const;
  int getMinAtkIv(int idx) const;
  int getMinDefIv(int idx) const;
  int getMinSpAtkIv(int idx) const;
  int getMinSpDefIv(int idx) const;
  int getMinSpeedIv(int idx) const;
  int getMinPowerHiddenPower() const;
  bool getEnableNatureFilter() const;
  QVector<bool> getNatureFilters() const;
  bool getEnableHiddenPowerTypesFilter() const;
  QVector<bool> getHiddenPowerTypesFilters() const;

  void setMinHpIv(const int minHpIv);
  void setMinAtkIv(const int minAtkIv, int idx);
  void setMinDefIv(const int minDefIv, int idx);
  void setMinSpAtkIv(const int minSpAtkIv, int idx);
  void setMinSpDefIv(const int minSpDefIv, int idx);
  void setMinSpeedIv(const int minSpeedIv, int idx);
  void setMinPowerHiddenPower(const int minPowerHiddenPower);
  void setEnableNatureFilter(const bool enableNatureFilter);
  void setNatureFilters(const QVector<bool> natureFilters);
  void setEnableHiddenPowerTypesFilter(const bool enableHiddenPowerTypeFilter);
  void setHiddenPowerTypesFilters(const QVector<bool> hiddenPowerTypeFilters);

private:
  QSpinBox* m_spnMinHpIv;
  QSpinBox* m_spnMinAtkIv[3];
  QSpinBox* m_spnMinDefIv[3];
  QSpinBox* m_spnMinSpAtkIv[3];
  QSpinBox* m_spnMinSpDefIv[3];
  QSpinBox* m_spnMinSpeedIv[3];
  QSpinBox* m_spnMinPowerHiddenPower;
  QVector<QCheckBox*> m_chkHiddenPowerTypes;
  QCheckBox* m_chkEnableHiddenPowerTypeFilter;
  QCheckBox* m_chkEnableNatureFilter;
  QWidget* m_naturesWidget;
  QWidget* m_typesWidget;
  QVector<QCheckBox*> m_chkNatures;
};
