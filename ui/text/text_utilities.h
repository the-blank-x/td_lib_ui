// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#pragma once

#include "ui/text/text_entity.h"

namespace Ui {
namespace Text {
namespace details {

struct ToUpperType {
	inline QString operator()(const QString &text) const {
		return text.toUpper();
	}
	inline QString operator()(QString &&text) const {
		return std::move(text).toUpper();
	}
};

} // namespace details

inline constexpr auto Upper = details::ToUpperType{};
[[nodiscard]] TextWithEntities Bold(const QString &text);
[[nodiscard]] TextWithEntities Semibold(const QString &text);
[[nodiscard]] TextWithEntities Italic(const QString &text);
[[nodiscard]] TextWithEntities Link(
	const QString &text,
	const QString &url = "internal:action");
[[nodiscard]] TextWithEntities PlainLink(const QString &text);
[[nodiscard]] TextWithEntities Wrapped(
	TextWithEntities text,
	EntityType type);
[[nodiscard]] TextWithEntities RichLangValue(const QString &text);
[[nodiscard]] inline TextWithEntities WithEntities(const QString &text) {
	return { text };
}

[[nodiscard]] inline auto ToUpper() {
	return rpl::map(Upper);
}

[[nodiscard]] inline auto ToBold() {
	return rpl::map(Bold);
}

[[nodiscard]] inline auto ToSemibold() {
	return rpl::map(Semibold);
}

[[nodiscard]] inline auto ToItalic() {
	return rpl::map(Italic);
}

[[nodiscard]] inline auto ToLink(const QString &url = "internal:action") {
	return rpl::map([=](const QString &text) {
		return Link(text, url);
	});
}

[[nodiscard]] inline auto ToRichLangValue() {
	return rpl::map(RichLangValue);
}

[[nodiscard]] inline auto ToWithEntities() {
	return rpl::map(WithEntities);
}

[[nodiscard]] TextWithEntities Mid(
	const TextWithEntities &text,
	int position,
	int n = -1);
[[nodiscard]] TextWithEntities Filtered(
	const TextWithEntities &result,
	const std::vector<EntityType> &types);

} // namespace Text
} // namespace Ui
