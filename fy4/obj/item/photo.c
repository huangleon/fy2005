// ; annie 07.2003
// dancing_faery@hotmail.com

// 

inherit ITEM;
#include <ansi.h>


string *female_weight_desc = ({
	MAG "�����е���������" NOR,
	BLU "�Ե���������" NOR,
	CYN "��̬��ӯ" NOR,
	CYN "�������" NOR,
    HIG "�����񻣬��������" NOR,
	HIG "���ǡ���ô�" NOR,
	NOR "���ֲ���" NOR,
	YEL "��̬΢��" NOR,
	YEL "��ķ���" NOR,
	WHT "�Ŀ�����" NOR,
	HIR "�ƺ��ü�����" NOR
});
string *male_strength_desc = ({
	BLU "������������" NOR,
	HIB "�������޸���֮��" NOR,
	CYN "����΢������" NOR,
	CYN "���˾�����������" NOR,
	HIG "���ս�Ӣ��" NOR,
	NOR "���Ĳ��ֲ���" NOR,
	YEL "�ж����������" NOR,
	YEL "����뺷" NOR,
	WHT "�Ŀ�����" NOR,
	HIR "�ƺ��ü�����" NOR
});



void create() {
	set_name("��ˮ����Ƭ", ({ "photo" }) );
	set("long", "����һ�Ű�ˮ����Ƭ��\n");
	set("unit", "��" );
}

string getfigure(object me) {	
	int str, ruler, level, exp, agi;
	exp =(int) me->query("combat_exp");
	str = me->query("str");
	agi = me->query("agi");
	if (me->query("gender")=="Ů��") {
	    str = str>50 ? 25 + str/2 : str;
	    str = str >25 ? str*10/(agi+1) + 20 : str;
	    ruler = sizeof(female_weight_desc)-1;
	    level = str >120 ? ruler : ( str/5 - str*str/1440) ;
	    level = level > ruler ? ruler : level; 
	    return female_weight_desc[level];
	}
	else {
	    str = str>60 ? 30 + str/3 : str;
	    str = str >30 ? str*10/(agi+1) + 20 : str;
	    ruler = sizeof(male_strength_desc)-1;
	    level = str >120 ? ruler : ( str/6 - str*str/1440) ;
	    level = level > ruler ? ruler : level; 
	    return male_strength_desc[level];
	}
}

string getper(object me, object obj) {
	int per;
	int spi;

	int weight, score;
	string str;

	per = obj->query_per();
	score = (int) obj->query("score");
	
	if((string)obj->query("gender") == "Ů��") {
		if(per >= 45) {
			str = HIG"�����Ѿ������ñ�ī���ݣ����֮�����˲��ɻ�ʧ��ᣡ\n"NOR;
		} else if(per >= 40) {
			str = score > 1000 ? 
				 "��ۼ���أ������˼����ӣ�\n" 
				:"���޾��ף���Ŀ�������������ߵ���\n" ;
		} else if(per >= 33) {
			str = score > 1000 ?  
				 "�����绨�������鲻�Խ�����������\n"
				:"���Ľ��ޣ���������ɢ����������ջ�\n";
		} else if(per >= 29) {
			str = "�г�������֮�ݣ������߻�֮ò��\n";
		} else if(per >= 24) { 
			str = score > 1000 ?  
				 "�������ˣ�һ�һЦ�䣬����������Ȼ�Ķ���\n"
				:"�������ʣ�һ˫�۾��ܻṴ�ˡ�\n";
		} else if(per >= 18) {
			str = "�������֣��������ˡ�\n"; 
		} else if(per >= 14) {
			str = "����ɰ�������ϲ�ˡ�\n"; 
		} else if(per >= 10) {
			str = "��òƽƽ�������ù�ȥ��\n";
		} else {
			str = "����ò��...�������ɡ�\n";
		}
	} else {
		if (per >= 35) {
			str = "�ǳ�Ư���ɰ���\n";
		} else if(per >= 30) { 
			str = "����������Ŀ��\n";
		} else if(per >= 26) {
			str = "����ͦ����ġ�\n";
		} else if(per >= 15) {
			str = "������ͷ���Եġ�\n";
		} else {
			str = "��ģ����,ͦ���˵ġ�\n";
		}
	}
	
	return str;
}

string inventory_look(object obj, int flag) {
	string str, desc;
	object me, left, right;

	str = obj->short();
	if(obj->query("equipped")) {
		if(!desc = obj->query("armor_worn")) {
			if(!desc=obj->query("weapon_wielded")) {
				desc = "��";
			} else {
				me = environment(obj);
				left = me->query_temp("left_hand");
				right = me->query_temp("right_hand");
				if(obj == left && obj == right) {
					desc = "˫��" + desc + "��";
				} else if(obj == right) {
					desc = "����" + desc + "��";
				} else {
					desc = "����" + desc + "��";
				}
			}
		}
		str = desc + str;
	} else if(!flag) {
		str = (environment(obj)->is_character() && !environment(obj)->is_corpse() ? 
				"����" : "  ") + str;
	} else {
		return 0;
	}
	
	return str;
}

void blink(object me)
{
	string str,pro,*desc;
	object *inv,obj;
	desc = // ������Ҫsinny���;
	({
		"����òģ������Ӱ����һ�š�",
		"������ɫ����������",
		"������Ĺ����ҵģ��ƺ�����ʲô������",
		"��ͫ��ͨ�죬�������׶�ɲ���",
	});
	obj = me;	// lazy blanche..
	pro = me->query("gender") == "Ů��"?"��":"��";
	set("name",me->query("name")+"����Ƭ");
	str = "����һ��"+me->query("name")+"����Ƭ��\n";
	str += me->long();
	str += pro+"��������"+chinese_number(me->query("age") / 10 * 10)+"�����"+me->query("national")+"�ˡ�\n";
	str += pro + getper(me,me);
	str += pro + getfigure(me) +"��\n";
	str += pro + COMBAT_D->eff_status_msg((int)me->query("eff_kee") * 100 
				/ (int)me->query("max_kee")) + "\n";
	str += pro + (obj->is_naked() ? "�������塣\n" : "");
	inv = all_inventory(obj);
	if(sizeof(inv))
	{
		inv = map_array(inv, "inventory_look", this_object(), ("����"=="��") ? 0 : 1 );
		inv -= ({ 0 });
		if(sizeof(inv))
			str += sprintf("%s\n", implode(inv, "\n  "));
	}
	// tatoo print
	if (obj->query_temp("body_print") ) str += obj->query_temp("body_print")+ "\n";
	str += pro;
	str += desc[random(sizeof(desc))];
	str += "\n";
	if (!random(10))
		str = "������Ƭ�յ��ǣ���ҹ����ѻ�ڷɡ�\n";
	set("long",str);
}


void init()
{
	blink(this_player());
}

