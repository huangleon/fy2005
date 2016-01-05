inherit SMART_NPC;
#include <ansi.h>

int show_me();

void create()
{
    set_name("������", ({ "king" }) );
    set("title","��������");
    set("gender", "����" );
//    set("group","guizi");
    set("age", 52);
    set("per",30);
    set("long","һ��������ף�ͷ����ڵĺ����ˣ����߾������е�һ�ŵͼ��ᣬ������
�Ž𱭣�����ȴ§��һ����Ů��������������Ц��\n");
	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("class","lama");	
	set("chat_chance",1);
    	set("chat_msg",({
			"��������Ц���������۸�λ������ʲ���ˣ���λ���书���գ�������С��
�㵹���ѣ�����С�������λ����һ�ã�С���Լ��ȸ�����Ϊ������\n",
			"������ü�������ɫ��������"YEL"����֮��"NOR"һʧ������Ǻã���\n",
    	}) );  
    
    	set("inquiry", ([
        	"����֮��" : 	(: show_me :),
        	"��ϼ":			"����֮��ԭ����������ʯ�ϳɣ�һ��������һ����ϼ��\n",
        	"����":			"����֮��ԭ����������ʯ�ϳɣ�һ��������һ����ϼ��\n",
   		]));
    	
    
    auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_u","kwan-yin-spells",1);    		
	setup();
	carry_object("/obj/armor/cloth",([	"name": "�����Ƥ��",
    						"long": "һ�������Ƥ�ۡ�\n",
    						"value": 80,
    						 ]))->wear();    
	carry_object("/obj/armor/hat",([	"name": HIY"�ֽ��"NOR,
    						"long": "һ�����ű�ʯ���ֽ�ڡ�\n",
    						"value": 100,
    						 ]))->wear();    
}
	
void init()
{       
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
	        if (!ob->query("zangbei/����_���ʳɹ�")) {
			ccommand("kick "+ob->query("id"));
			message_vision(CYN"������������������С���������Ǳ�����������ã���Ͱ��������ɳĮ��ιЫ�ӡ�\n"NOR,ob);
			return;
		}
	
		if (ob->query("gender")=="Ů��") {
			message_vision(CYN"��������Ц������λ�뿴�����ǵ����ù�����ԡ֮�ᣬ�ǲ��Ǹ����ˣ�\n"NOR,ob);
			return;
		}
	
		message_vision(CYN"��������Ц�����ҵĺ�Ů�������������λ��������˭�أ��Ҽǵ����︽��������
֮�ڣ���û�����Ӣ��������ѽ��\n"NOR,ob);
		return;
        }

}


int show_me(){
	object me;
	
	me= this_player();
	if (REWARD_D->check_m_success(me,"����֮��")) {
		command("say лл���������һ��˼���֮�ǣ�");
		return 1;
	}
	
	if (!REWARD_D->riddle_check(me,"����֮��")) {
		message_vision(CYN"
�����������㣬ҡҡͷ˵����������è�Ĺ��򣬻���ʲô���¶���\n"NOR,me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"����֮��")==1) {
		command("sigh");
		message_vision(CYN"
��������̾�����ǡ�����֮�ǡ�����������ֵ���ǵı�ʯ���ɣ�һ����ϼ��
һ�������������ҹ��ȴ���֮����û�ϵ�����ǰ��ϼ��Ϊ�˵��ߣ���˵��
�����������Ϊ���⡢�������Ǻã�\n"NOR, me);
		return 1;
	}
			
	if (me->query_temp("zangbei/����_�����ͱ�")) {
		message_vision(CYN"
���������е�˵����������ô���ˣ�\n"NOR,me);
		return 1;
	}
				
	if (REWARD_D->riddle_check(me,"����֮��")==2) {
	message_vision(CYN"
��������̾�����������У��������а����⼫��֮���еĳ���Ҳ����������
֮�֡�С������ί���������廢���͵ġ�С��Ҳ֪������ʮ�ֿɿ������Բ�
�ҽ����������ν������ǣ��벻�����ǣ����ֵ����˴˿̾���ɥ��������
��ȻҲ���˱��������ˡ����Է�Ҫ��ʮ�����ƽ�����������ȴû�����¿�
�Ե������Ρ�׳ʿ��Ը��Ϊ�һ������Ǯ�ƣ�\n"NOR,me);
	me->set_temp("zangbei/guizi_talk",1);
	return 1;
	}

	return 1;
}

int do_answer(string arg){
	object me,item;
	me = this_player();
	
	if (!me->query_temp("zangbei/guizi_talk")) return 0;
	if (!arg || (arg!= "yes" && arg!="no")){
		return notify_fail("answer yes ���� no\n");
	}
	
	if (arg == "no") {
		message_vision(YEL"$N�ŵ�һ���飬��æ�������ˡ�\n"NOR,me);
		me->delete_temp("zangbei/guizi_talk");
		return 1;
	}
	
	if (arg == "yes"){
		message_vision(YEL"$N�����ظ�˵�����¶��Ͱ����ۼ������ˡ�\n"NOR,me);
		me->delete_temp("zangbei/guizi_talk");
		command("touch "+me->query("id"));
		item = present("cun piao",this_object());
		if (!item) item = new(__DIR__"obj/cundan");
 		item->set("item_owner",me);
		if (item->move(me)){
			message_vision(CYN"
�������ó�һ��˵���ã�������ԭ�Ϲ�Ǯׯ�Ĵ�Ʊ���ɴ�������ʮ���ɳĮ
�У��Է���Ȼ���˽�Ӧ���㡣\n"NOR,me);
			me->set_temp("zangbei/����_�����ͱ�",1);
		} else {
			message_vision("������˵�������������Ϻ���û�ط�Я���ҵĶ�������\n",me);
			destruct(item);
		}
		return 1;
	}

	return 1;
}

int accept_object(object me, object item){
	object real_gem;
	mapping data;
	
	if (REWARD_D->check_m_success(me,"����֮��"))	return 0;
		
	if (item->name()==HIM"����֮��"NOR) {
		if ( item->query("item_owner")!=me) {
			message_vision(CYN"
������˵����"HIM"����֮��"NOR+CYN"��Ȼ��·���������ԭ����Ҳ�Ͳ������ˣ�
������˵�����߿��ߣ������Ҿͱ����ˣ�\n"NOR,me);
			return 1;
		}
		
		message_vision(CYN"
������˵��"HIM"����֮�ǣ�����֮�ǣ�"NOR+CYN"�㾹Ȼ�ҵ�������ϼ��̫лл�ˣ�\n"NOR, me);
		REWARD_D->riddle_set(me,"����֮��",2);
		command("say ��ϧ��"HIY"����֮��"NOR+CYN"����ʧ���⣬û���������Ҹ�����������");
		return 1;
	}
	
	if (item->name()==HIY"����֮��"NOR ) {
 if (item->query("item_owner")!=me || !me->query_temp("zangbei/����_������")) {
			message_vision(CYN"
������˵���⼫��֮����Ȼ��·���������ԭ����Ҳ�Ͳ������ˣ�
������˵�����߿��ߣ������Ҿͱ����ˣ�\n"NOR,me);
			return 1;
		}
		command("touch "+me->query("id"));
		message_vision(CYN"
��������Ц���������İ������ҿ����ҵ�����ı��أ�����ָ�տɴ���\n"NOR,me);
		REWARD_D->riddle_done( me, "����֮��", 50, 1);
		data = ([
			"name":		"����֮��",
			"target":	me,
			"att_1":	"agi",
			"att_1c":	1,
			"mark":		1,
		]);
		
		REWARD_D->imbue_att(data);	
		
		return 1;
	}
	message_vision(CYN"
������˵����ֻ���һ����ǻ����ʵ�ļ���֮�ǡ�\n"NOR,me);
	return 0;
}		

