// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"����"NOR, ({ "zouzhe" }) );
	set_weight(70);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�ҽ���ӣ���̫��������СŮ�����Ҹ������ٵ�ʱ��\n��ص��˶�˵���Ǹ���١���ض�����������д����̡�\n�Ҳ���Ϊ�����ѹ���ҲΪ���������̵������ġ�һ���˿�\nȥ�žͳ��˲зϣ���ȥ�˱��ӣ������ٰ���ȥ���Ժ����\n��Ĺ����£�Ҳû�а취�ˡ�����Ը���ٸ�û��Ϊū澣�\n�游������������и��Ĺ����µĻ��ᡣ\n");
		set("value", 200);
		set("no_split",1);
		set("unit", "��");
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("lore",1);
	}
	::init_item();
}