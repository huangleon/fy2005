// armor.h

/*		fengyun 4.1 �����ض���	--2/20/2003 by Silencer

��������ע����ͨʹ���߲������κγ�װ��������ԣ��޷������ȣ������ǽ�����Ҫ��
������	�������������õķ��߽�����ڣ����꣯������������ά����
��������ʩ��ָ�ɣ����ߣ�����������������һ��������
���������������У�����������𣯣���򣯣����Ҫ�����ڣ�����󣯣������С�
������	�����ԣ�����Ч�ã�ʩ���ȵĻ��߽������ۺ���롣
�����������������������ĺ����ǣ�����������Ϊһ����Ʒ������������Ϊ������Ʒ��
	
	HEAD: 	ͷ��ͷ����������(0-30-50)����parry(0-5-20)���ض�Ч��PARRY_HIT��+per 0-5
	BOOTS:	������(0-5-20)����dodge(0-10-30)���ض�Ч��DODGE_HIT��
	CLOTH: 	����ͷ��������ض��߷������������ԣ�Resistance��ʩ����
		(0-50-200) + parry/dodge/force(0-0-10)�ȡ�		
	SHIELD: ��������(0-20-50) ���������£̣ϣãˣ���Ҫ��Ӧ�������������á�
	FINGER����ָ�����ԣ�ʩ����		+3per ����
	SURCOAT:���磬��������(0-10) ��ͨʹ�á�
	
	NECK��	���飬��ͨʹ�á�
	WRIST��	˿����ͨʹ�á����� per (1-3)
	WAIST��	��������ͨʹ�á�
	HAND��	���ף���ͨʹ�á�
	
	MASK: 	�������ר�ã��������κ��������ԡ�
	ARMOR: --- ��������
*/

#ifndef	__ARMOR__
#define	__ARMOR__

// Standard	inheritable	armor objects.
#define	HEAD		"/std/armor/head"
#define	MASK		"/std/armor/mask"
#define	NECK		"/std/armor/neck"
#define	CLOTH		"/std/armor/cloth"
#define	ARMOR		"/std/armor/armor"
#define	SURCOAT		"/std/armor/surcoat"
#define	WAIST		"/std/armor/waist"
#define	WRISTS		"/std/armor/wrists"
#define	SHIELD		"/std/armor/shield"
#define	FINGER		"/std/armor/finger"
#define	HANDS		"/std/armor/hands"
#define	BOOTS		"/std/armor/boots"

// Standard	armor types
#define	TYPE_HEAD		"head"
#define	TYPE_MASK		"mask"
#define	TYPE_NECK		"neck"
#define	TYPE_CLOTH		"cloth"
#define	TYPE_ARMOR		"armor"
#define	TYPE_SURCOAT		"surcoat"
#define	TYPE_WAIST		"waist"
#define	TYPE_WRISTS		"wrists"
#define	TYPE_SHIELD		"shield"
#define	TYPE_FINGER		"finger"
#define	TYPE_HANDS		"hands"
#define	TYPE_BOOTS		"boots"

// Standard	armor desc
#define	WORN_HEAD		"ͷ��"
#define WORN_MASK		"����"
#define	WORN_NECK		"����"
#define	WORN_CLOTH		"��"
#define	WORN_ARMOR		"��"
#define	WORN_SURCOAT		"����"
#define	WORN_WAIST		"����"
#define	WORN_WRISTS		"����"
#define	WORN_SHIELD		"��ִ"
#define	WORN_FINGER		"ָ��"
#define	WORN_HANDS		"�ִ�"
#define	WORN_BOOTS		"�Ŵ�"

#endif
