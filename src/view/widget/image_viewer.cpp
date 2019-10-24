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

#include "view/widget/image_viewer.h"

#include <DWidgetUtil>
#include <QApplication>
#include <QDebug>
#include <QPainter>
#include <QResizeEvent>
#include <QStackedLayout>
#include <QtCore/QTimer>
#include <QDesktopWidget>
#include <QLabel>
#include <DStyle>
#include "view/theme_manager.h"
DWIDGET_USE_NAMESPACE
namespace dman {

namespace {

const int kBorderSize = 12;
const int kCloseBtnSize = 48;

}  // namespace

ImageViewer::ImageViewer(QWidget *parent)
    : QDialog(parent)
{
    this->setObjectName("ImageViewer");
    this->initUI();

    connect(close_button_, &Dtk::Widget::DIconButton::clicked,
            this, &ImageViewer::close);
}

ImageViewer::~ImageViewer()
{

}

void ImageViewer::open(const QString &filepath)
{
    qDebug() << Q_FUNC_INFO << filepath;

    // Escape uri.
    QString abspath(filepath);
    if (abspath.contains("://")) {
        QUrl url(abspath);
        abspath = url.path();
    }

    QPixmap pixmap(abspath);
    const QRect screen_rect = qApp->desktop()->screenGeometry(QCursor::pos());
    const int pixmap_max_width = static_cast<int>(screen_rect.width() * 0.8);
    const int pixmap_max_height = static_cast<int>(screen_rect.height() * 0.8);
    if ((pixmap.width() > pixmap_max_width) ||
            (pixmap.height() > pixmap_max_height)) {
        pixmap = pixmap.scaled(pixmap_max_width,
                               pixmap_max_height,
                               Qt::KeepAspectRatio,
                               Qt::SmoothTransformation);
    }

    this->move(screen_rect.topLeft());
    this->resize(screen_rect.size());
    this->showFullScreen();

    img_label_->setPixmap(pixmap);
    img_label_->setFixedSize(pixmap.width(), pixmap.height());
    QRect img_rect = img_label_->rect();
    img_rect.moveTo(
        static_cast<int>((screen_rect.width() - pixmap.width()) / 2.0),
        static_cast<int>((screen_rect.height() - pixmap.height()) / 2.0));
    img_label_->move(img_rect.topLeft());

    // Move close button to top-right corner of image.
    const QPoint top_right_point = img_rect.topRight();
    close_button_->move(top_right_point.x() - kCloseBtnSize / 2,
                        top_right_point.y() - kCloseBtnSize / 2);
    close_button_->show();
    close_button_->raise();
}

void ImageViewer::initUI()
{
    img_label_ = new QLabel(this);
    img_label_->setObjectName("ImageLabel");

    //close_button_ = new Dtk::Widget::DIconButton(this);
    close_button_ = new DIconButton(DStyle::StandardPixmap::SP_CloseButton, this);
    close_button_->setObjectName("CloseButton");
    close_button_->raise();
    close_button_->setFocusPolicy(Qt::FocusPolicy::NoFocus);


    this->setContentsMargins(kBorderSize, kBorderSize, kBorderSize, kBorderSize);
    this->setWindowFlags(Qt::FramelessWindowHint |
                         Qt::BypassWindowManagerHint |
                         Qt::Dialog |
                         Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setModal(true);

    //ThemeManager::instance()->registerWidget(this);
}

void ImageViewer::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    this->hide();
}

void ImageViewer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(0, 0, this->width(), this->height(), QColor(0, 0, 0, 77));
}

}  // namespace dman
