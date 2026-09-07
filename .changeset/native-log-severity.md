---
libwebrtc: patch
---

Preserve native WebRTC warning and error severity in the Rust log bridge. Keep native info at debug and verbose at trace so normal operation does not enable the native diagnostic stream.
