#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();

void create()
{
    	set_name("����",({"han tang","han"}));
//	set("title","��������");
   	set("long","
���Ĳ���Ұ���������׶�ֻ����üĿ��·����Ǵ���һ��˵��������Į֮
�⣬����˭��û���Ӻ����׽�������ȻҲ��Ը���κ����׽��������ʲô��
����������վ��ԶԶ�ġ��������߽����߳�֮�ڣ������̾ͻ��ߵø�ԶЩ��
�������ϲ�����ǰ��Ҳ����û���˼��������ڡ�\n");
     	
     	set("gender","����");
     	set("group","juyuan");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",8500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"�ϲ�":	"�����ϲ���ʲô�����ǶԵģ������ϲ�������ô�����Ҷ�������Թ��",
		"����":"�����ϲ���ʲô�����ǶԵģ������ϲ�������ô�����Ҷ�������Թ��",
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"\n������������ԣ��������������ѱ�����ס�����;�������������
�������ڵ�����������\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","demon-strike",2);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "������",
    						"long": "һ���û���Ƥ֯�ɵĳ��ۡ�\n",
    						"value": 10, 
    						 ]))->wear();    
 
}

void init()
{       
        object ob;

        ::init();
        if (environment(this_object())->query("home"))
        if( interactive(ob = this_player()) && !query("in_show") && !is_fighting() ) {
				if (REWARD_D->riddle_check(ob,"��԰����")==5	)
//                if (ob->query("marks/kuaihuo/��԰�̿�")==2 
//                	&& !ob->query("marks/kuaihuo/����"))
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
	object me, peng1, peng2, peng3, peng4;
        if( !ob || environment(ob) != environment() ) return;
	set("in_show",1);
	delete("chat_chance");
	message_vision(CYN"
��Ȼ���ĸ����»����ı��δ󺺼�һ��ܹ���������Χס�˺��ġ�

��ͷһ�˵�������������������

��������Ҳ���̱������Լ������գ�

���޽��޽�������

����������������

��ԭ��ԭŭ������

ԭ��������������ʮ����������Ĵ�����������ϻ�û���κ����ܵ����Ը������ĸ���\n"NOR,ob);
	peng1 = new(__DIR__"peng1");
	peng1->move(environment());
	peng2 = new(__DIR__"peng2");
	peng2->move(environment());
	peng3 = new(__DIR__"peng3");
	peng3->move(environment());
	peng4 = new(__DIR__"peng4");
	peng4->move(environment());
	peng1->do_ask(ob);
	return;
}



void die(){
	object *inv;
	int i, check, num;
	
	inv = all_inventory(environment(this_object()));
	num = sizeof(inv);
	for (i=0;i<num;i++){
		if (inv[i]->query("group")=="khlr") {
			destruct(inv[i]);
			check = 1;
		}
	}
	if (check)
		message_vision("\nֻ������һ�������´�����ʧ�ںڰ��\n",this_object());
	::die();
}
		