#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("Ѧ��",({"xue dahan","xue","dahan"}));
		set("title","���ֺú�");
   		set("long","
һ����߰˳ߵı��δ󺺣���򼸺���ƽ����������һ˫���Ȱ��
���ִ������������Ѹǹ���ϥ�ǣ�����ȧ�Ǹ��ʣ���������ɨ����
Ũü��һ�Ŵ��졣�����ϴ����·���Ȼ�������ƣ���һվ�𣬿�����
�����ݣ����˿��ź��¡�\n");
     	set("gender","����");
    	set("age",32);
    	 	
    	set("combat_exp",4300000);  
   	
    	set("reward_npc",5);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );
        
        set("death_msg","Ѧ�󺺳��������˿������·��Ǳ�����̾Ϣ�����ұ�������㵱�����ѵġ�\n");
        
        set("inquiry", ([
        	"Ѧ��" : "�Ҹ��˳������Ѿ�ʮ�����ˣ�Ҫ�����������Ե���ѩɽ
����ȥ����һ��Ѧ��ׯ��\n",
		"xuebin" : "�Ҹ��˳������Ѿ�ʮ�����ˣ�Ҫ�����������Ե���ѩɽ
����ȥ����һ��Ѧ��ׯ��\n",
      	]));
            	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"Ѧ�󺺻��Ƴ�����������ʮ���µ�ͷ���µ�ͷ��Ѫ��������������Ӣ���ᣬɱ�����ĳ���ͷ����\n",
			"Ѧ������ƴ�������ع��¼��ڻ���ƣ�ĨĨ���Ц������\n",
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","zhangjian",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/wine1");
}
