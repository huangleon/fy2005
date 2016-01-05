// ghost.c

#include <ansi.h>
inherit NPC;

/*int	*range = ({
		2,3,5,7,11,17,25,35,45,55,				// L1 - 10
		66,77,89,102,115,129,143,158,174,191,			// L11 - 20
		209,228,248,270,293,319,346,376,406,438,		// L21 - 30
		470,504,538,573,608,644,680,718,757,797,		// L31 - 40
		837,879,921,964,1008,1052,1098,1144,1192,1240,		// L41 - 50
		1289,1338,1388,1438,1490,1542,1596,1650,1706,1764,	// L51 - 60
		1823,1882,1942,2003,2066,2129,2194,2259,2326,2395,	// L61 - 70
		2464,2536,2609,2684,2761,2841,2921,3003,3085,3168,	// L71 - 80
		3251,3335,3419,3504,3589,3676,3763,3852,3941,4031,	// L81 - 90
		4123,4216,4311,4407,4504,4602,4700,4800,4900,5000,	// L91 - 100
	});
*/

int ask_me();
int annie_drug()
{
	object me = this_player();

	if (me->query_temp("annie/find_herb/����") 
		&& me->query_temp("annie/find_herb/������") 
		&& me->query_temp("annie/find_herb/��С��") 
		&& me->query_temp("annie/find_herb/����") 
		&& me->query_temp("annie/find_herb/����ѩ") 
		&& me->query_temp("annie/find_herb/Ҷ��ʿ")	)
	{

		message_vision(query("name")+"�ٺ�һЦ������Ȼ����ʶ�ô˲ݣ������˵��������˵���������\n",me);
		if (REWARD_D->riddle_check(me,"�������") != 3
			&& REWARD_D->riddle_check(me,"�������") != 4)
		{
			message_vision(query("name")+"˵������ҩ�ĸ���Ҳ������֮���Ҳ����ָ�����ˡ�\n",me);
			return 1;
		}
		else
		{
			message_vision(query("name")+"��������������������ֻ����������ھ�Ȫ֮�£�����\n",me);
			REWARD_D->riddle_set(me,"�������",4);
			return 1;
		}
	}
	message_vision(query("name")+"�ӻ��֣�ȥ���ʱ���ȥ���������Ϸ�\n",me);
	return 1;
}

void create()
{
        set_name("÷������", ({ "mei da", "meida"}) );        
        set("title",WHT"�񵽲���"NOR);
        set("age", 65);
        set("long","һ������߹ڵ����ˣ�����ָ��������ͯ��ϴ���ϵı�ѩ����������������
÷�Ҷ��ϵ��ϴ�÷���������书��Σ�����û��֪������Ϊ����û�˸Һ�
�������֡�÷��������ҽ����˵������������������С��ɵ���Ѱ������Ҳ
�ܹ����Ķ��ݡ�������˭�����и���ʧ��˭�ָҵ�����һλ���ǣ�������÷
�������Ӳ������˿�������ʹ�Ǵ����Ҳ��Ҫ��Ǯ�ġ�����������ʲô��
����֢���������������β����¶���\n");
        
        set("combat_exp", 8000000);
        set("inquiry", ([
        		"���̲�" : 	(: annie_drug :),
        		"����" : 	(: ask_me :),
             	"hurt" :	(: ask_me :),
             	"recover":	(: ask_me :),
             	"cure":	(: ask_me :),
             	"�β�":		(: ask_me :),
   	]));
    	      
        setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init() {
	add_action("do_cure","cure");
	::init();
}



int ask_me(){
	int exp, cost;
	object me;
	int level;
	
	me = this_player();
	if (!me->query("attr_apply/strength")
		&& !me->query("attr_apply/intelligence")
		&& !me->query("attr_apply/composure")
		&& !me->query("attr_apply/agility")
		&& !me->query("attr_apply/constitution")
		&& !me->query("attr_apply/karma")
		) {
		message_vision(CYN"÷������һ���ִ�ס$N�����ţ������˵���޲����֣���������ǲ�Ϸ����ţ�\n"NOR,me);
		me->set_temp("marks/cheat_meida",time());
		return 1;
	}
		
	level = me->query("level");
	
	message_vision(CYN"÷�������������ң��������µش�����$N����˵�����������Σ����Ϸ�Ӳ����Ȿ����������\n"NOR,me);
	tell_object(me, WHT"�ָ�һ��������Ҫ"+chinese_number(level*2)+"�����ӣ����Ƿ�Ը�⣿\n"NOR);
	tell_object(me, WHT"�������Ǯׯ���㹻�Ĵ�����<cure ������>\n"NOR);
	return 1;
}
	
int do_cure(string arg) {
	
	int exp, level, cost;
	object me;
	
	string cure;
	
	me = this_player();
	if (!arg)
		return notify_fail("��ʽ��cure�������ݣ�
���У����ݣ�Ϊ���� caizhi������ tizhi������ liliang���ٶ� sudu��
���� yunqi������ dingli	\n");
		      	
		switch (arg) {
		
		case "����" :
		case "int":
		case "intelligence":
		case "caizhi" :	cure = "intelligence"; 	break;			
        
        case "����" :
        case "str":
        case "strength":
        case "liliang": cure = "strength"; 	break;			
        
        case "����" :
        case "con":
        case "constitution":
        case "tizhi" :	cure = "constitution"; 	break;			
        
        case "����" :
        case "kar":
        case "karma":
        case "yunqi" :	cure = "karma"; 	break;			
        
        case "�ٶ�" :
        case "agi":
        case "agility":
        case "sudu" :	cure = "agility"; 	break;			
        
        case "����" :
        case "cps":
        case "composure":
        case "dingli":	cure = "composure"; 	break;			
        
        default :
			return notify_fail("û��������ԡ�\n");
	}
	
	if (!me->query("attr_apply/"+cure) || me->query("attr_apply/"+cure)>=0)
		return notify_fail("���"+arg+"û�����ˡ�\n");
	
	level = me->query("level");
	cost = level * 200;

	if (me->query("deposit")< cost)
		return notify_fail("���Ǯׯ����"+ chinese_number(level*2) +"�����ӡ�\n");

	if (cost < 0)	cost= 0;
			
	me->add("deposit",-cost);
		
	message_vision(YEL"÷������΢΢һЦ����һ�����ɫ��ҩ������$N���С�������\n"NOR,me);
	tell_object(me,WHT"��ֻ���̺����絶�ҩ����ǣ�����ȴ��̹����ࡣ\n"NOR);
	me->add("attr_apply/"+cure,1);
	return 1;
}
	

int accept_object(object who, object item){
	if (item->query("value") > 10000) {
		message_vision("÷������Ц������˵�����á��ã����͡���\n",who);
		who->delete_temp("marks/cheat_meida");
		return 1;
	}
	message_vision("÷��������$N˵�������������ô��ֵǮ����\n",who);
	return 0;
}