#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("���",({"labor",}));
    	set("long","
��վ�����򣬵�λ��Ȼ��΢��ȴ�ǹ�ϵ����վ�����Ĳ�ʹ����������
�����ڵص�С�����������ն����⣬������Ҳ���������������ֻҪ��
���������ӣ��Ϳ���ƽ��Ѹ�ٵؽ����ػ���ԭ��\n");
  	set("gender","����");
    	
    	set("combat_exp",1500000);  
    	set("attitude", "friendly");
    	
    	set_skill("fork",200);
    	set_skill("parry",200);
    	set_skill("dodge",200);
    	
    	set("inquiry", ([
                "��������" : 	"�ðѶ��Ұ��Ƕ��������������һ�°ɡ�\n\n",
				"����" : 	"�ðѶ��Ұ��Ƕ��������������һ�°ɡ�\n\n",
				"��������":	"�ðѶ��Ұ��Ƕ��������������һ�°ɡ�\n",
				"ɳĮ": "�����ҵ����նӣ���ɳĮ�ֿ��ְ�ȫ��\n",
				"desert": "�����ҵ����նӣ���ɳĮ�ֿ��ְ�ȫ��\n",
				"camel": "�����ҵ����նӣ���ɳĮ�ֿ��ְ�ȫ��\n",
				"����": "�����ҵ����նӣ���ɳĮ�ֿ��ְ�ȫ��\n",
				"���ն�": "�����ҵ����նӣ���ɳĮ�ֿ��ְ�ȫ��\n",
				"С��":	"С�˾�˵�ڹ��ڹ����գ�������Ҳ����̫�����\n",
        ]));
    	
    	
    	set("death_msg",CYN"\n$N˵�������ˣ�����ɱͷ�ɡ��� \n"NOR);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n���е������˰���ɱ����������\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    		"�����æ���ҵش�ɨ���������ﲻ�鲻Ը������š�\n",
    		"���˵����˭�ܰ��Ұ���Щ��������һ���أ���\n",
    		"�����������ԡ��������ԡ���������\n",
    		
    	}) );    	    	
    	
    	
	setup();
    	carry_object(__DIR__"obj/ycloth")->wear();      
    	carry_object(AREA_TAIPING"obj/brokenrake")->wield();
}

int accept_object(object who, object item){
	object ob;
	object room;
	
	ob = this_object();
	room = find_object(AREA_QUICKSAND"yizhan");
	
	if (!room || !room->query("route_clear")) {
		message_vision("
�����̾����˵�������·�ϲ�̫ƽ���Ҹ���ԭ��ͷʧ����ϵ��
�����նӵ�����Ҳ�������ˡ�����\n",this_object());
		return 1;
	}
	if ((item->query("value")<300 && !who->query("ʯ����/desert_route"))
		|| item->query("value")<300) {
		message_vision("
���Ϊ�ѵ�ҡҡͷ�������Ǯ�����������ղݶ�����������\n",ob);
		return 0;
	}
	if (who->is_busy()) {
		message_vision("���˵�����͹��ƺ������¶�û�˰ɣ���\n",ob);
		return 0;
	}
		
	message_vision("���������Ц��˵�����͹٣����������·����\n",ob);
	message_vision("
���Ӻ���ǣ��һͷ�ִ���׳�����գ�$Nһ����������ȥ��\n",who);
	message_vision("$N����ߺ�ȣ������նӳ���ඣ���\n",ob);
	who->set_temp("ride","����");
	who->start_busy(16);
	environment()->go_out_1(who, 0);
	return 1;
}
