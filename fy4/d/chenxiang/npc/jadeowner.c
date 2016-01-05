#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
    	set_name("֣��", ({ "zhengjia", "zheng" }) );
    	set("gender", "����" );
    	set("age", 39);
    	set("title", "�鱦��");
    	set("long", "�������������ϵȵ����񣬶��Ҽ�Ǯ����\n");
    	set("combat_exp", 17000);
    	set("attitude", "friendly");
    	
    	set_skill("dodge", 100);
    	set_skill("parry", 120);
    	set("vendor_goods", ([
	        __DIR__"obj/jade1":120,
	        __DIR__"obj/jade2":120,
	        __DIR__"obj/jade3":120,
	        __DIR__"obj/jade4":120,
        ]) );
    	set("inquiry", ([
        	"����" : 	"����û�е���������������򼸿�����Ȼ����ʯ���ӹ��\n",
        	"yubotao" : "����û�е���������������򼸿�����Ȼ����ʯ���ӹ��\n",
        	"��ʯ��" : 	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"wang" :	"��ʯ��������������ģ��������ϵ����Ĵ���ˡ�\n",
        	"�����":	"�������������Ǹ�����Ƥ�����Ӭ��ô��\n",
        	"����":		"�������������Ǹ�����Ƥ�����Ӭ��ô��\n",
        	"�Ŷ���":	"�Ŷ������Ŷ�����ԭ����Ӣ�����������Ǹ�������̽�������ˡ�\n",
        ]));
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " ֣��Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "����������֣��򼸿�ɣ� \n");
                        break;
                case 1:
                        say( " ֣��Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����Ǽ���֮����򼸿�ɡ� \n");
                        break;

        }
}


int accept_object( object who, object item){
		
		if (item->query("name") == HIM"�Ͼ���ʯ"NOR && item->query("jile")==1){
			if (REWARD_D->riddle_check(who,"�Ͼ�֮��")==2 
				|| REWARD_D->riddle_check(who,"�Ͼ�֮��/֣��")) {
				command("shake");
				command("say �㻹�����Ҹ��˰ɡ�");
				return 0;
			}
			
			
			message_vision(CYN"$N����"+item->query("name")+NOR+CYN"���˼��£����ó�����Ƭ����Ƭ�̣�üͷ������\n"NOR, this_object());
			ccommand("hmm");
			ccommand("say �����ܣ������ܣ����Ͼ���λ����������û������");
			REWARD_D->riddle_set(who,"�Ͼ�֮��/֣��",1);
			
			if (sizeof(who->query("riddle/�Ͼ�֮��"))==4) {
				tell_object(who, CYN"\n"+name()+CYN"˵��ֻ��һ���˻�֪����鱦ʯ���������������ֽйŶ�����
��˵������������͸������ϵ��ڹ�Ĺ���ת����ڵ��׵�����ת�ı��
û������֪�������ģ���һ��֪���ⱦʯ�ĵ�ϸ��\n");
				REWARD_D->riddle_set(who,"�Ͼ�֮��",2);
			}
			return 0;
		}
			
		if (item->query("thief_obj")){
			command("say С�겻����������֮�");
			return 0;
		}
				
}

void reset()
{
    set("vendor_goods", ([
        __DIR__"obj/jade1":120,
        __DIR__"obj/jade2":120,
        __DIR__"obj/jade3":120,
        __DIR__"obj/jade4":120,
        ]) );
}
