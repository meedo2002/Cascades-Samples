/*!
* Copyright (c) 2012, 2013 Research In Motion Limited.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef REGISTERSERVICE_HPP
#define REGISTERSERVICE_HPP

#include "ConfigurationService.hpp"
#include "../dao/UserDAO.hpp"

#include <QtCore/QObject>
#include <QtNetwork/QNetworkReply>

namespace pushcollector
{

/*!
 * Offers services related to the handling / processing of registration.
 */
class PUSHCOLLECTOR_EXPORT RegisterService : public QObject
{
    Q_OBJECT

public:
    RegisterService(QObject *parent = 0);

    void subscribeToPushInitiator(const User& user, const QString& token);

Q_SIGNALS:
    void piRegistrationCompleted(int code, const QString &description);

private Q_SLOTS:
    /*!
     * Slot function that is called when the network request to the
     * push initiator is complete.
     */
    void httpFinished();

    /*!
     * Slot function connected to the _accessManager sslErrors signal.
     */
    void onSslErrors(QNetworkReply * reply, const QList<QSslError> & errors);

private:
    ConfigurationService m_configurationService;

    QNetworkAccessManager m_accessManager;
    UserDAO m_userDAO;
    QNetworkReply *m_reply;

    User m_currentUser;

    QString deviceVersion() const;
    QString deviceModel() const;
};

} // namespace pushcollector
#endif
