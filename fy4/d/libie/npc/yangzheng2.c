#include <ansi.h>

inherit NPC;
void create()
{
        set_name("���", ({ "yang zheng","yang","zheng" }) );
        set("long",
                "һ����������ڡ���������������ʮ��ĺ��ӣ���������ϡ�\n");

        set("attitude", "friendly");
	set("age",32);
        set("str", 80);
        set("cor",70);
        set("agi",50);

        set("con",70);
	set("title", HIW"��ͷ"NOR);

        set("combat_exp", 4000000+random(1000000));
        set("max_force",3000);
        set("force",3000);
        

	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("libie-sword",200);
	set_skill("parry",1000);
	set_skill("dodge",200);
	set_skill("feixian-steps",200);

	map_skill("sword","libie-sword");
	map_skill("dodge","feixian-steps");

        setup();

        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/tieflag/obj/leavehook")->wield();
}

void heart_beat()
{
	object me,room,yang;
	int msg;
	string file;
	
	yang=this_object();
	room=environment();

	if(msg=query("dying_msg"))
	{
		me=room->query("���2����");
		if(msg==5)
			message_vision(YEL"$N���������������ĵ�ʬ�壬��û��ע�⵽$n���˽�����\n"NOR,yang,me);
		if(msg==4) {
			message_vision(YEL"$N߽����������ġ����ҡ���ʤ�ˡ����Ӵ���Ҳû��˭�������������
�ˣ�����������Ҳ�����ԡ���������\n"NOR,yang);
		}
		if(msg==3)
			message_vision(YEL"\n$N��ɫ��ȻתΪƽ����������������𹳣���Ȼ���Լ��Ŀڲ��䣬$n
��ʧɫ������������ֹ��ȴΪʱ����\n"NOR,yang,me);
		if(msg==2)
			message_vision(YEL"\n$N��$n΢Ц��������ĳ���ʵ��ʣ��������޺���ֻ��"+RANK_D->query_respect(me)+"�ܽ��ҷ򸾶�
�˺�����Сľ�������������\n"NOR,yang,me);
		if(msg==1)
			{
				message_vision(YEL"$N����Խ��ԽС�������ĵ����������ĵ���ߡ�\n"NOR,yang);
				REWARD_D->riddle_done(me,"���",200,1);
				me->delete("libie");
				me->delete_temp("libie");	// ��������ڿ������mark�������������ǽ������ǵ�һ�ε�
				
				// RECORD the first one.
				
				file = "/log/riddle/LIBIE_LOG";
				if (file_size(file)== -1)
				{
					log_file("riddle/LIBIE_LOG",
						sprintf("%s(%s) �⿪�����, %s \n",
						me->name(1), geteuid(me),ctime(time()) ));
					REWARD_D->riddle_done(me,"���괫��",1000,1);
				}					
				me->set_temp("libie/���_β��",1);
				yang->die();
			}
		add("dying_msg",-1);
	}
	::heart_beat();
}

void dying(object me)
{
	set("dying_msg",5);
}



void die()
{	object me,corpse,*inv,room;
	int i;

	room=environment();
	if(me=room->query("���2����"))
		me->delete_temp("libie/���_Ŀ�������");
	corpse=new("/d/libie/obj/yangcorpse2");
	corpse->move(room);
	inv=all_inventory(this_object());
	i=sizeof(inv);
	while(i--)
		inv[i]->move(corpse);
	message_vision("�������\n",this_object());
	destruct(this_object());
		
}

