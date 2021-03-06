/* Copyright (c) 2012 Research In Motion Limited.
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

import bb.cascades 1.2

Container {
    minHeight: 150

    background: Color.create ("#272727")

    Container{
        topPadding: 30
        leftPadding: 30
        rightPadding: 30
        bottomPadding: 30

        layout: StackLayout {
            orientation: LayoutOrientation.LeftToRight
        }

        ImageView {
            rightMargin: 30
            image: ListItemData.icon
        }

        Label {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }

            text: ListItemData.text
            textStyle.color: Color.create("#fafafa")

            multiline: true
        }
    }

    Divider {}
}
