#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIY"����"NOR, ({ "emperor robe","robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long","��ɫ���ƣ������ʯ��Ƭ��Ե�����Ľ��������ʮ���£�������ɫ�ƣ���ǰ���������������Ҽ�����������һ���Ͷ�������һ���·��˱���ˮȹ��ʯ����\n���׺��һ��С�֣���Ӱ���ơ�\n");
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

