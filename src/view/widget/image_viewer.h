/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEEPIN_MANUAL_VIEW_WIDGETS_IMAGE_VIEWER_H
#define DEEPIN_MANUAL_VIEW_WIDGETS_IMAGE_VIEWER_H

#include <QDialog>
#include <dimagebutton.h>

class QLabel;

namespace dman {

class ImageViewer : public QDialog {
  Q_OBJECT
 public:
  explicit ImageViewer(QWidget* parent = nullptr);
  ~ImageViewer() override;

 public slots:
  void open(const QString& filepath);

 protected:
  void mousePressEvent(QMouseEvent* event) override;

  void paintEvent(QPaintEvent* event) override;

 private:
  void initUI();

  QLabel* img_label_ = nullptr;
  Dtk::Widget::DImageButton* close_button_ = nullptr;
};

}  // namespace dman

#endif  // DEEPIN_MANUAL_VIEW_WIDGETS_IMAGE_VIEWER_H
