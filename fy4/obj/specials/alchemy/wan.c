#include <ansi.h>
inherit ITEM;
void generate_name();
void create()
{
	generate_name();
	set_weight(1);
	set("unit", "��");
    set("long", "һ���������Ƶ�"+name()+"��\n");
	set("value", 0);
	set("no_get", 1);
	set("no_give", 1);
	::init_item();
}

void init(){
	add_action("do_use", "use");
}

int do_use(string arg){
	object me;
	
	string usage;
	me = this_player();
	if(!arg || (arg != "wan" && arg != "medicine")){
		return notify_fail("��Ҫ��ʲô��\n");;
	}
	usage =(string) query_temp("usage");
	if (usage == "ʯ��") me->set("water", me->max_water_capacity());
	if (usage == "����") me->set("force",(int) me->query("max_force"));
	if (usage == "��ʳ") me->set("food",me->max_food_capacity());
	if (usage == "�ط�") me->set("mana",(int) me->query("max_mana"));
	if (usage == "����") me->set("atman",(int) me->query("max_atman"));
	if (usage == "����") me->apply_condition("hehe", 2 + random(8));
	if (usage == "����") me->clear_condition();
	message_vision( HIY"$Nȡ��һ��$n"HIY"������У�һ���Ƶ����Ļƹ�͸��$N���⣡��\n" NOR, me, this_object());
   
	destruct(this_object());
	return 1;
}

void generate_name(){
	string *color = ({HIC, HIG, HIW, HIY, HIR, MAG});
	string *number = ({"��", "��", "��", "��", "��", "��", "��","��","��","��"});
	string *part = ({"��", "ľ", "ˮ","��", "��"});
	string *race = ({"ʯ��", "����","��ʳ", "�ط�", "����","����","����"});
	string usage = (race[random(sizeof(race))]);
	set_name( (color[random(sizeof(color))])+(number[random(sizeof(number))]) 
		   + (part[random(sizeof(part))])
		   + usage
		   + "��"NOR, ({ "wan" , "medicine"}) );
	
	set_temp("usage", usage);
}
