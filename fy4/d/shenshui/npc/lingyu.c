// XXDER

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������" , ({ "lingyu", "girl", "ling yu" }) );
	set("long", "���ߴ��϶�����һ��Ů����������徵�����û��һ˿���飬һϮ��ɴ��
������������ӣ�һ˫�۾�����ҹ�ղ��õ����ǡ����ƺ������˳�˼��
���ƺ����������������۹������ڴ����ĳһ�㡣\n\n");
	set("attitude", "friendly");
	
	set("inquiry", ([
		"ocean" : "�������صģ���˵������һ�����˾�ס�����\n",
		"��" : "�������صģ���˵������һ�����˾�ס�����\n",
		"����": "��˵�е����ˣ������һ��������ˮ�����ɺ�����\n",	
		"�̺�����":"������ˮ����ƽ���������¹������������沨ǧ����δ�������������"		
	]) );

	set("chat_chance", 1);
	set("chat_msg", ({
     name()+"�����ؿ��Ŵ���ĺ��Σ��ƺ�û��ע�⵽��Ĵ��ڡ�\n",
    }) );

	set_skill("parry", 180);
	set_skill("charm", 180);
	set_skill("nine-moon-force",180);
    	    		
	set("age", 14);
	set("gender", "Ů��" );
	set("per", 30);
	set("combat_exp", 5000);
	setup();
	carry_object(__DIR__"obj/blackcloth")->wear();
}

int answer_react(object me, string arg){
    	object mask;
    	
    	if(arg == "dunno" && !query("given")) {
        	message_vision("\n$N������һ��˵��������ȷʵ��һ�����ص����磬����˭���Ǹ���������˽��أ���\n", me);      
        	message_vision("$N΢Ц�ŵݸ�$nһ������ͬʱ˵������Ҳ����һ������õ��������\n", this_object(), me);
        	mask = new(__DIR__"obj/jiaoxiao"); 
        	set("given",1);
        	me->delete_temp("marks/lingyu_asked");
        	mask->move(me);    
    	} else if(arg == "no"){
        	message_vision("$N���ִ�Ц˵��������ֻ�����Ǹ���С���ӵĴ�˵���ˡ���\n",me);
        	message_vision("\n$N΢΢һЦ˵��������ô���������ͬʱ$N�����ƺ�΢΢һ����\n", this_object());
        	me->delete_temp("marks/lingyu_asked");
        	tell_object(me, "\nֻ����һ���Ʒ�Ϯ������һ�����ذδ����������Ȼ������һ�գ���\n");
        	tell_object(me, "��Ȼһ���������ѴӴ��ڷ��˳�ȥ��\n");
        	message("vision", "\n" + me->name() + "һ�����ذδ������ȥ������һ������������ʧ�ڴ��⡣\n", 
                environment(me), me);
        	environment(me)->fall_out(me); 
    	} else if(arg == "yes"){
        	message_vision("\n$N���������ţ��׺����������ᣬ��������������������ǵ����֯��������
�����ع�������\n", me);
	    	message_vision("$Nע�Ӵ����˫Ŀת�˹�������$nһ�£�һ˿Ц�ݸ����������ϣ������
����������ؽ�������,������˵����һ�仰��\n", this_object(), me);
    		me->delete_temp("marks/lingyu_asked");
    	}
	return 1;
}
