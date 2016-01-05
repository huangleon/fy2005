#include <ansi.h>
inherit __DIR__"annieitem";

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



void create()
{
	set_name("����", ({ "statue"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
	set("unit", "��");
	set("desc", "
һ����û�п������ӵĵ�������԰����̳���ϲ���˵����ӣ�mimic��
����ԴӼҾߵ깺��Ҽ���װ���� ��decorate�������˹Ҽ��ĵ���ͻ�
����������������������벻����Ч����blessing statue���� ������
һ�����������ֻ�ܷ����ιҼ���\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","m");
	set("lore_item",1);
	set("size",1);
	set("value", 500000);
	set("tax",5);
	set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player()) {
	   	add_action("do_mimic","mimic");
	   	add_action("do_decorate","decorate");
	   	add_action("do_touch", "blessing");
	}
}

int do_touch(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	mapping buff;
	string type,name;
	int amount,n;
	string *list = ({ "apply/karma","apply/armor","apply/damage","apply/composure","apply/agility","apply/strength" });
	int  *list_m = ({ 1, 10, 10, 1, 1, 1 });
	string *list_c = ( {"����","����","�˺���","����","�ٶ�","����" });
				
	if (!arg) 
		return 0;
	
	if (present(arg,env) != ob)
		return 0;
	
	if (!env->is_owner(me->query("id"))) {
		tell_object(me,"����������ֻ�����˲���ʹ�á�\n");
		return 1;
	}

	if (me->is_fighting() || me->is_busy()) {
		tell_object(me,"��������æ����һ����ɡ�\n");
		return 1;
	}
	
	message_vision("$NС���������������һ��"+name()+"��\n", me);

	if (!query("text3") || query("text3")>3 || query("text3")<1 ){
		tell_object(me,"���ֱ��䣬��ʲôҲû��������Ҫ���˹Ҽ��Ż�����Ч��\n");
		return 1;
	}
	
	if (me->query("timer/house_statue") + 899 > time()) {
		tell_object(me,"������ű�ף��������һ��������ɡ���ÿ�μ���������ӣ�\n");
		return 1;
	}
	
	if (!ANNIE_D->check_buff(me,"statue"))
	{
		n = random(sizeof(list));
		type = list[n];
		amount = list_m[n] * query("text3");
		name = list_c[n];
		
		
		if (!random(8000)) {		// 8000 *15 = 2000 hour to get 20mins +3 int chance, just for fun :D
			type = "apply/intelligence";
			amount = query("text3");
			name = "����";
		}
		
		buff =
		([
			"caster":ob,
			"who":me,
			"type":"statue",
			"att":"bless",
			"name":"Ϧ�ռҾӡ�"+name,
			"buff1": type,
			"buff1_c":amount,
			"time":900,
			"buff_msg":CYN"$N"CYN"ֻ��һ�����������������壮����\n"NOR,
		]);
		ANNIE_D->buffup(buff);
		me->set("timer/house_statue",time());
		tell_object(me,WHT"�����"+ name + "�����"+ amount + "�㣩\n"NOR);
		
	}else
		tell_object(me,"���ֱ��䣬��ʲôҲû�����������Ѿ��������ƵĹ�Ч�ˣ�\n");

	return 1;
}


int do_decorate(string arg){
	
	object env, item, me;
	string deco;
	me = this_player();
	
	if (!arg)
		return notify_fail("��������һ���Ҽ���װ�Σ�\n");
		
	if (arg != "statue pendant")
		return notify_fail("��ֻ���üҾߵ���۵ĵ���Ҽ���װ�Ρ�\n");
	
	item = present(arg, me);
	if (!item)
		return notify_fail("������û�������Ʒ��\n");
		
	if (item->query("item_type")!= "xx")
		return notify_fail("��ֻ���üҾߵ���۵ĵ���Ҽ���װ�Ρ�\n");
	
	env = environment();
	
	if (query("text3") && query("text3")>= 3)
		return notify_fail("�������Ѿ������ٷŹҼ��ˡ�\n");
	
	message_vision("$N��"+item->name()+"С������ط���"+name()+"�����ϡ�\n", me);
	
	add("text3", 1);
	
	if (query("text3")==1) deco = HIG"������"NOR;
		else if (query("text3")==2) deco = HIG"ɺ������"NOR;
		else deco = WHT"��������"NOR;
	set("desc","����һ��"+name()+"�����Ŀ��ȥ��ֻ����\n"+query("text")+"  ���Ϲ���һ��СС��"+ deco+"��\n");
	
	destruct(item);
	reset_item_list(environment());
	return 1;
	
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
	
	if((string)obj->query("gender") == "Ů��")
	{
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
	}
	else if((string)obj->query("gender") == "����") {
		if (per >= 35) {
			str = "��ò����,������һ��\n";
		} else if(per >= 30) { 
			str = "������棬�������ٷ硣\n";
		} else if(per >= 25) { 
			str = "Ӣ��������ò���˰���\n";
		} else if(per >= 20) {
			str = "�����������������\n";
		} else if(per >= 15) {
			str = "��ٶ�����\n";
		} else if(per >= 10) {
			str = "������ʵ���޷���ά��\n";
			//str = "��ͷ���ԣ��ܻ�������ӡ�\n";
		} else {
			str = "��òƽƽ��\n";
		}
	}
	else {
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

string blink(object obj)
{
	string str,pro,*desc;
	object *inv,me=obj;
	if (me->query("gender") == "Ů��")
		pro = "��";
	else if (me->query("gender") == "����")
		pro = "��";
	else
		pro = "��";
	str = "";
	str += pro+"��������"+chinese_number(me->query("age") / 10 * 10)+"��������ӡ�\n";
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
	return str;
}

int do_mimic(string arg)
{
	object target;
	object me = this_player(),env=environment(me),ob=this_object();
	string sheet, deco;

	if (!arg)
		return notify_fail("ָ���ʽ��mimic <Ŀ��>\n");
	if (!env->is_owner(me->query("id")))
		return notify_fail("����������ֻ�����˲���ʹ�á�\n");
	if (query("text"))
		return notify_fail("��������Ѿ�����һ�����ˡ�\n");
	target = find_player(arg);
	if( !target ) target = find_living(arg);
	if (!target)
		return notify_fail("�����˰��죬�����벻����Ҫ��̵�����ʲô���ӡ�\n");
	sheet = blink(target);
	message_vision(CYN"$N���踫�䣬�����½�����̳�"+target->name()+CYN"�����ӡ�\n"NOR,me);
	set("text",sheet);
	set("text2",target->name());
	set("name",query("text2")+"�ĵ���");
	if (!query("text3"))
		set("desc", "����һ��"+name()+"�����Ŀ��ȥ��ֻ����\n"+query("text")+"\n");
	else {
		if (query("text3")==1) deco = HIG"������"NOR;
		else if (query("text3")==2) deco = HIG"ɺ������"NOR;
		else deco = WHT"��������"NOR;
		set("desc","����һ��"+name()+"�����Ŀ��ȥ��ֻ����\n"+query("text")+"  ���Ϲ���һ��СС��"+ deco+"��\n");
	}
		
	reset_item_list(env);
	return 1;
}

int restore_item()
{
	object item, env;
	mapping item_list,mitem;
	string *lists,str, deco;
	int i,idx;

	env = environment();
	item_list = environment()->query("stock_"+query("item_type"));
	
	if (environment()->query("stock_"+query("item_type")+"/text3")){
		set("text3",environment()->query("stock_"+query("item_type")+"/text3"));
		if (query("text3")==1) deco = HIG"������"NOR;
		else if (query("text3")==2) deco = HIG"ɺ������"NOR;
		else deco = WHT"��������"NOR;
	}
	
	// û���κ����֡�
	if (!environment()->query("stock_"+query("item_type")+"/text")
		||!environment()->query("stock_"+query("item_type")+"/text2") ) {
		if (!query("text3"))	return 1;
		else 
			set("desc","һ����û�п������ӵĵ�������԰����̳���ϲ���˵����ӣ�mimic��
  ���Ϲ���һ��СС��"+ deco+"��\n");		
		return 1;
	}
	
	set("text",environment()->query("stock_"+query("item_type")+"/text"));
	set("text2",environment()->query("stock_"+query("item_type")+"/text2"));
	set("name",query("text2")+"�ĵ���");

	if (!query("text3"))
		set("desc", "����һ��"+name()+"�����Ŀ��ȥ��ֻ����\n"+query("text")+"\n");
	else {
		set("desc","����һ��"+name()+"�����Ŀ��ȥ��ֻ����\n"+query("text")+"  ���Ϲ���һ��СС��"+ deco+"��\n");
	}	
	return 1;
}

int reset_item_list(object dest)
{
	environment()->set("stock_"+query("item_type")+"/text",query("text"));
	environment()->set("stock_"+query("item_type")+"/text2",query("text2"));
	environment()->set("stock_"+query("item_type")+"/text3",query("text3"));
	environment()->save();
	return 1;
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
