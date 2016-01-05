// ghost.c

#include <ansi.h>
inherit NPC;

int ask_me();

int annie_drug()
{
	object me = this_player();

	if (REWARD_D->riddle_check(me,"�������") == 4
		|| REWARD_D->riddle_check(me,"�������") == 5)
	{
		message_vision(query("name")+"���������������µش�����$N��\n",me);
		message_vision(query("name")+"���ͷ�����ţ���Ȼ�г��ġ�\n",me);
		message_vision(query("name")+"˵���������̲�ô�����ϵ��£�ֻ�����ꡣ\n",me);
		message_vision(query("name")+"˵������һ�������鷿��ǻʵ��϶������ԣ�\n",me);
		message_vision(query("name")+"˵�����ڶ������ڻ�ɽ����ɽ���Ķ����䣬��ݱ����Ķ���\n",me);
		message_vision(query("name")+"˵����������˵Զ��Զ��˵�������������˼䣬���ڻ�Ȫ������\n",me);
		message_vision(query("name")+"˵������ֻ������ȥѰȥ�ʣ���Ͷ��ˡ�\n",me);
		REWARD_D->riddle_set(me,"�������",5);
		return 1;
	}
	message_vision(query("name")+"���ֵ���ȥ��ȥ��ȥ�������ҺȾƣ�\n",me);
	return 1;
}

void create()
{
        set_name("÷������", ({ "mei er", "meier"}) );        
        set("title",WHT"�������С�"NOR);
        set("age", 65);
        set("long","
���˴��ż���ϴ�ķ��׵����ۣ��������ؿ��ϣ�ȴ��մ�������壬һ˫�ֵ�
ָ����Ҳȫ�����ۣ���Ȼ���Ŷ���ʿ������ͷ��ȴ�Ҳݰ�¶�����棬һ��
���ֻ����ݣ����������Ǹ�������š���������������÷�Ҷ��ϵ��϶���÷
��������ҽ����Ȼ�Ȳ���÷��ȴҲ�а׹�����֮�ܣ�ֻ��ϧ������ƣ���
��ϡ��ƽ����������һ�챻��һƺ�����ȡ������������ү����ƽ�ؾ��˵�
���£��������������ﶺ����������÷�������Ӳ������˿�������ʹ�Ǵ��
��Ҳ��Ҫ��Ǯ�ġ�����������ʲô������֢���������������β����¶���\n");
        
        set("combat_exp", 8000000);
        set("inquiry", ([
        	"��ɽ":		"�������Ķ�����ȥ��ɽ�������Լ���취�ɡ�\n",
        	"���鷿":	"ʲô���Ͻ����ˣ������ɣ�����취��ѡ���ϣ�Ӯ�˾��ܽ�ȥ�ˡ�\n",
        	"��Ȫ":		"��ѽ����ֻ���Ҹ�����ȥѰȥ�ʣ���Ͷ��ˡ�\n",		
        	"���̲�" : 	(: annie_drug :),
        	"����" : 	(: ask_me :),
             	"hurt" :	(: ask_me :),
             	"cure" :	(: ask_me :),
             	"recover":	(: ask_me :),
             	"�β�":		(: ask_me :),
   	]));
    	      
        setup();
        carry_object("/obj/armor/ghost_cloth",(["name": "ϴ�ķ��׵�����",
    						"long": "һ��ϴ�ķ��׵����ۡ�\n",
    						"value": 0,
    						 ]))->wear();    
}


void init() {
	add_action("do_cure","cure");
	::init();
}



int ask_me(){
	int exp, cost, level;
	object me;
	
	me = this_player();
	if (!me->query("attr_apply/strength")
		&& !me->query("attr_apply/intelligence")
		&& !me->query("attr_apply/composure")
		&& !me->query("attr_apply/agility")
		&& !me->query("attr_apply/constitution")
		&& !me->query("attr_apply/karma")
		) {
		message_vision(CYN"÷���������ִ�ס$N���������������������˵�����߿��ߣ������Ϸ�ľ��ˣ�\n"NOR,me);
		return 1;
	}
		
	cost = me->query("level")*2;
	message_vision(CYN"÷���������ִ�ס$N�����ţ���Ȼ��ʧɫ������������������������
Ψ�Ϸ��ܾ��㣬�����㻹���˻��Ǹ���è����\n"NOR,me);
	tell_object(me, WHT"�ָ�һ��������Ҫ"+chinese_number(cost)+"�����ӣ����Ƿ�Ը�⣿\n"NOR);
	tell_object(me, WHT"�������Ǯׯ���㹻�Ĵ�����<cure ������>\n"NOR);
	return 1;
}
	
int do_cure(string arg) {
	
	int exp, cost, level;
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
	cost = 200 * level;
	
	if (me->query("deposit")< cost)
		return notify_fail("���Ǯׯ����"+ chinese_number(level*2) +"�����ӣ�
�������Ǹ���������������ĸ������ˣ����Ӽõ�ɡ�\n");		

	
	if (cost < 0)	cost= 0;
	me->add("deposit",-cost);
	
	message_vision(CYN"÷������������Ц���������ϴ��˿�����������\n"NOR,me);
	tell_object(me,BLU"��ֻ������ɭɭ��һ����º����ȴ��̹����ࡣ\n"NOR);
	me->add("attr_apply/"+cure,1);
	return 1;
}
	
int is_ghost()
{
	return 1;
}