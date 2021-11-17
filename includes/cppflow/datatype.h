//
// Created by serizba on 12/7/20.
//

#ifndef CPPFLOW2_DATATYPE_H
#define CPPFLOW2_DATATYPE_H

namespace cppflow {

	using datatype = TF_DataType;

	/**
	 * @return A string representing dt
	 *
	 */
	inline std::string to_string(datatype dt) {
		switch (dt) {
		case datatype::TF_FLOAT:
			return "TF_FLOAT";
		case datatype::TF_DOUBLE:
			return "TF_DOUBLE";
		case datatype::TF_INT32:
			return "TF_INT32";
		case datatype::TF_UINT8:
			return "TF_UINT8";
		case datatype::TF_INT16:
			return "TF_INT16";
		case datatype::TF_INT8:
			return "TF_INT8";
		case datatype::TF_STRING:
			return "TF_STRING";
		case datatype::TF_COMPLEX64:
			return "TF_COMPLEX64";
		case datatype::TF_INT64:
			return "TF_INT64";
		case datatype::TF_BOOL:
			return "TF_BOOL";
		case datatype::TF_QINT8:
			return "TF_QINT8";
		case datatype::TF_QUINT8:
			return "TF_QUINT8";
		case datatype::TF_QINT32:
			return "TF_QINT32";
		case datatype::TF_BFLOAT16:
			return "TF_BFLOAT16";
		case datatype::TF_QINT16:
			return "TF_QINT16";
		case datatype::TF_QUINT16:
			return "TF_QUINT16";
		case datatype::TF_UINT16:
			return "TF_UINT16";
		case datatype::TF_COMPLEX128:
			return "TF_COMPLEX128";
		case datatype::TF_HALF:
			return "TF_HALF";
		case datatype::TF_RESOURCE:
			return "TF_RESOURCE";
		case datatype::TF_VARIANT:
			return "TF_VARIANT";
		case datatype::TF_UINT32:
			return "TF_UINT32";
		case datatype::TF_UINT64:
			return "TF_UINT64";
		default:
			return "DATATYPE_NOT_KNOWN";
		}
	}

	/**
	 *
	 * @tparam T
	 * @return The TensorFlow type of T
	 */
	template<typename T>
	TF_DataType deduce_tf_type() {
		if (std::is_same<T, float>::value)
			return datatype::TF_FLOAT;
		if (std::is_same<T, double>::value)
			return datatype::TF_DOUBLE;
		if (std::is_same<T, int32_t >::value)
			return datatype::TF_INT32;
		if (std::is_same<T, uint8_t>::value)
			return datatype::TF_UINT8;
		if (std::is_same<T, int16_t>::value)
			return datatype::TF_INT16;
		if (std::is_same<T, int8_t>::value)
			return datatype::TF_INT8;
		if (std::is_same<T, int64_t>::value)
			return datatype::TF_INT64;
		if (std::is_same<T, unsigned char>::value)
			return datatype::TF_BOOL;
		if (std::is_same<T, uint16_t>::value)
			return datatype::TF_UINT16;
		if (std::is_same<T, uint32_t>::value)
			return datatype::TF_UINT32;
		if (std::is_same<T, uint64_t>::value)
			return datatype::TF_UINT64;

		throw std::runtime_error{ "Could not deduce type!" };
	}

	/**
	 * @return  The stream os after inserting the string representation of dt
	 *
	 */
	inline std::ostream& operator<<(std::ostream& os, datatype dt) {
		os << to_string(dt);
		return os;
	}

}
#endif //CPPFLOW2_DATATYPE_H
