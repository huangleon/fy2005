#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����ƽ̨");
        set("long", @LONG
��ɽ���������µ������Ϣ���÷�����̧�ۻ�����ֻ����֪���о���������
ʮ�ɸߣ��������亹���졣��Ŀ�Ĺˣ�ȴ��������һ������ԿյĶ���ƽ̨�ϡ���
ƽ̨����ʮƺ��Բ�����ǰ����ٿգ��ϼȲ��ã����ֲ��ܣ���������·һ����
LONG
        );
	set("no_fly",1);
	set("no_fight",1);
	set("no_magic",1);
	set("coor/x",-40);
	set("coor/y",200);
	set("coor/z",100);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	if (userp(this_player()))
	{
		add("count",1);
		if (query("count") == 2)
			call_out("attack",10,this_player());
	}
}

int attack(object ob)
{
	if (!ob)
		ob=this_player();
	message_vision(CYN"�����������޼ʣ�ȴͻȻ�������������´�����\n"NOR,ob);
	call_out("do_ggyy",1,ob,ob,0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	int i,j;
	object item,env=this_object();
	string msg;
	string *event_msg = ({
"ſ���±�������ֻ����ͺͺ��ʮ��ʯ��֮�¾��ǹȵף�������ʮ����ˣ�ɮ������\n��ɫ��磬�������ŵ�ǹ��ꪣ���������Χ�Ÿ�������Ů������ȥ����Ů��\n���������䵱������ˮ������\n\n",
"ȴ��ˮ����������λ����ذգ��ֽ̽����˿�ʵ�ǲ��ڽ��С�\n",
"����һ�����˺ߵ���ħ�̹�Ȼ�ô�ļ��ӣ�������֮��Ҳ��֪����\n",
"ˮ��������һ�����������������ڣ�СŮ�Ӽ�ʶǳ�������е��������뵣����\n",
"���������ḫ��һ����Ц����Ц����Ϊ������������Ҳ��֪���˶������֣�����\n��������������ëѾͷ�����仰����򷢣�\n",
"ˮ����΢һ��ü��˵������λҪ�����ģ���������ʾ�¡�\n",
"���ߵĵ���Ӧ���������������Ҫ������������ħ����һ���������ִ�ⲻ\n�����ã�Ҳ�͹ֲ�����������ǿ���ˡ�\n",
"ˮ������̾�˿�����Ҳ�գ�����������ˣ�СŮ��ֻ�ö����ֽ̡�ȴ��֪��λԸ\n���г��ִͽ̣�\n",
"��ǰ�ǵ��˺ٺٸ�Ц��������Ѱ������ͬ�����ԣ���Ȼ����һ��һ���Ը�������\nħ�����֣��ֺαؽ�ʲô������أ�\n",
"ˮ����΢΢��ɫ��ԭ��������������ѵ��������̣��������۸���һ������Ů��\nΪ���ˣ�\n",
"����ʦ��Ҫ�𻰣��ͼ��ǳָ�֮���������ۣ���������������������ˣ���\nȻ�޻���˵����������ˣ������ٺ٣����ٲ���Ҫ�㱾���ӿ���\n",
"ˮ���������ֳ�ŭ�⣬������ָ��������˫�۴�ȥ������ʦ��̾һ�����ȵ���\n��Ҷ����ְգ�\n",
});
	if (!me || !target)
		return;
	if (environment(target) != env)
		return;
//	if (me != environment(target) || target->is_fighting())
//		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,target);
	if (count == 0)
	{
		me = new(__DIR__"npc/shui");
		me->move(env);
		this_object()->get_taoist();
		this_object()->get_monk();
	}
	if (count == 1)
	{
		this_object()->get_nun();
		this_object()->get_tx();
		this_object()->get_others();
	}
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{
		this_object()->fight(me);
		return;
	}
	return;
}

get_taoist()
{
	object *inv, ob;
	string *sname=({"����","����","����","��׾","����","�ɺ�","����","����",
});
	string *snick=({"����","����","���","����","��Ȩ","���","����","ҡ��",
});

	int i ;
	for (i=0; i<8;i++ )
	{
		ob=new(__DIR__"npc/taoist");
		ob->move(this_object());
	}
	ob=present("wudang taoist", this_object());
	if(ob) ob->set("name","���ҵ���");
	if(ob) ob->set("nickname",HIY"����"NOR);
	if (ob) ob->set("resistance/kee",65);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "wudang taoist" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]+"����");	
				inv[i]->set("nickname",CYN+snick[i]+NOR);
			}
		}
	}
}


get_monk()
{
	object *inv, ob;
	string *sname=({"���","����","����","����",// ����...*snicker
});
	string *snick=({HIW"ǰ�η���"NOR,"����Ժ����","�ƾ�������","����������",
});

	int i ;
	for (i=0; i<4;i++ )
	{
		ob=new(__DIR__"npc/monk");
		ob->move(this_object());
	}
	ob=present("shaolin monk", this_object());
	if(ob) ob->set("name","����ʦ");
	if(ob) ob->set("nickname",HIW"ǰ�η���"NOR);
	if (ob) ob->set("resistance/kee",70);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "shaolin monk" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]+"��ʦ");	
				inv[i]->set("nickname",HIR BLK+snick[i]+NOR);
			}
		}
	}
}


get_nun()
{
	object *inv, ob;
	string *sname=({"��Ҷ","��ѩ","��ͤ",
});

	int i ;
	for (i=0; i<3;i++ )
	{
		ob=new(__DIR__"npc/nun");
		ob->move(this_object());
	}
	ob=present("sanqing nun", this_object());
	if(ob) ob->set("name","��Ҷʦ̫");
	if (ob) ob->set("resistance/kee",60);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "sanqing nun" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]+"ʦ̫");	
			}
		}
	}
}

get_others()
{
object ob;
	ob=new(__DIR__"npc/cici");
	ob->move(this_object());
	ob=new(__DIR__"npc/khl");
	ob->move(this_object());

}

get_tx()
{
	object *inv, ob;
	string *sname=({"����","����",
});

	int i ;
	ob=new(__DIR__"npc/txmale");
	ob->move(this_object());
	ob=new(__DIR__"npc/txfemale");
	ob->move(this_object());
	if(ob) ob->set("name","����");
	if(ob) ob->set("nickname",HIG"С����"NOR);
	if (ob) ob->set("resistance/kee",60);
	inv = all_inventory();
	if(ob)
	{
		ob->dismiss_team();
		for(i=0 ;i < sizeof(inv);i++)
		{
			if(inv[i]->query("id") == "tiexue apprentice" && inv[i]!= ob)
			{
				ob->add_team_member(inv[i]);
				inv[i]->set("name",sname[i]);	
				inv[i]->set("nickname",HIG"���з"NOR);	
			}
		}
	}
}

fight(object me)
{
	object *inv, ob;
	int i;
	inv = all_inventory();
	for(i=0 ;i < sizeof(inv);i++)
	{
		if(inv[i]->query_temp("condition_type") == NOR CYN" <ɽ����>"NOR && inv[i]!= me)
		{
			inv[i]->kill_ob(me);
			me->kill_ob(inv[i]);
		}
	}
}
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
/*
goto /d/bashan/hole3;update here;updatep /d/bashan/npc/;call here->attack();l
*/
