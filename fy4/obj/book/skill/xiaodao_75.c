// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

//inherit ITEM;
#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
    set_name(HIG"ТŮ��"NOR, ({ "xiaoflower"}));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "��");
		set("no_split",1);
		set("long","һ�������ޱȵĲ廨��������Ů�·����˲����˼䷲�\n");
		set("value", 200);
		set("material", "plant");
		set("armor_prop/personality", 20);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N����ذ�һ��$n����ͷ�ϣ�˲�����ų�"HIM"��"HIG"��"HIY"��"HIR"��"NOR"��\n");
		set("unwield_msg", "$NС�ĵذ�$n��ͷ�ϳ���������\n");
		set("female_only", 1);   
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("lore",1);

		set("skill", ([
            "name":         "xiaodao",    
           "exp_required": 2150000,      
			"sen_cost":	5,	
			"difficulty":	5,	
            "max_skill":    74,      
		]) );
	}
    	::init_head();
}
