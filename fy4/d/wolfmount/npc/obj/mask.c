#include <ansi.h>
inherit EQUIP;
void create()
{
	set_name(HIY"�ƽ����"NOR, ({ "golden mask","mask" }) );
	set_weight(1000);
	set("long","һ���ƽ��̶��ɵ���ߣ��ɶ��칤�����ޱȡ�\n");
	set("unit", "��");
	set("value", 100);
	set("material", "cloth");
	set("level_required",999);	// Damn those masks make ppl NPCs id
	set("armor_type", "mask");
	set("fakegender", "����");
	set("armor_prop/id", ({"sun legate"}));
	set("armor_prop/name", ({"̫��ʹ��"}));
	set("armor_prop/short", ({HIY"̫��ʹ��"NOR+"(sun legate)"}) );
}