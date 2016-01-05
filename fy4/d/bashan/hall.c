#include <room.h>
#include <ansi.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "���");
        set("long", @LONG
����һ���̻Ի͵Ĵ��������������������˰������ڴ�����롣����
֮�䣬����һ���ɺ쳤̺����̺��ͷ��ʯ����������һ�ž���������һ�ž��Σ�
���ξ�������񻨣���ҫ���ƽ�ɫ�Ĺ�â��
LONG
        );
	set("no_fly",1);
	set("exits",([
  		"north" : __DIR__"hole4",
	]) );
	set("item_desc", ([
		"north": "�����Ŵ˿��������ţ����Ƿ���ˮ�����򿪡�\n",
	]) );
	set("objects", ([
	__DIR__"obj/master" : 1,
					]) );
	set("coor/x",-40);
	set("coor/y",220);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	if (userp(this_player()))
	{
		add("count",1);
		if (query("count") == 2)
			call_out("attack",16,this_player());
	}
}
int valid_leave(object me, string dir)
{
	if (dir == "north")
		return notify_fail("������ٲ���ͻȻ����һ��������ת������\n");
}

int attack(object ob)
{
	object *inv,p1,p2;
	int i;
	if (!ob)
		ob=this_player();
	message_vision(CYN"�������ʯ���ȻŲ�����ߣ�¶������һ��������\nˮ�����Ӱ��������˳�����һ��֮�£���ʱ����Ϯ����\n"NOR,ob);
	ob=new(__DIR__"npc/shui2");
	ob->move(this_object());
	inv = all_inventory(this_object());
	for (i=0;i<sizeof(inv) ;i++ )
	{
		if (inv[i]->is_corpse() || !inv[i]->is_character() || inv[i]==ob) continue;
		ob->kill_ob(inv[i]);
		if (userp(inv[i]) && !p1)
			p1=inv[i];
		else if (userp(inv[i]))
			p2=inv[i];
	}
	if (p1 && p2)
			CHANNEL_D->do_sys_channel(
			"sys", sprintf("%s(%s)��%s(%s)�����˰�ɽ��\n",
	                p1->query("name"),p1->query("id"),p2->query("name"),p2->query("id")));

	call_out("do_opengate",10,p1,p2,ob);
	return 1;
}

int do_instantsmash(object p1,object p2,object ob,int i)
{
	object me,who,room;
	mapping data;

	

	if (!ob)
		return 0;
	if (!p1 && !p2)
		return 0;
	
	if (query("done"))
		return 1;
	else
		set("done",1);
	
	if (!p1)
	{
		me=p2;
		tell_object(me,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		message_vision(HIY"\n��ö���Ž���С������$N����бб���˹���������\n\n"NOR,me);
		message_vision(HIW"һ��˸Ŀ�������ӹ��������ţ�ࣣ���һ����������\n�����죬�·����˼����ǵ��ᴥ���㻹û�з�Ӧ����\n����������ʲô����ǰ��ֻʣһƬããѩ�ף�����\n"NOR,me);

        environment(me)->set("short","����");
        environment(me)->set("long","�����һ�ж��Ѿ����ˣ�����ով���һ���ƽ٣���������ʬ�嶼��������ֻ\n�ܿ���һƬ�ڽ�֮�к�����Щ�ʺ���̵ĺۼ�������\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","��ɢ����Ůը������Ƭ��");
		me->add_temp("block_msg/all",-1);
		me->die();	
		return 1;
	}
	if (!p2)
	{
		me=p1;
		tell_object(me,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		message_vision(HIY"\n��ö���Ž���С������$N����бб���˹���������\n\n"NOR,me);
		message_vision(HIW"һ��˸Ŀ�������ӹ��������ţ�ࣣ���һ����������\n�����죬�·����˼����ǵ��ᴥ���㻹û�з�Ӧ����\n����������ʲô����ǰ��ֻʣһƬããѩ�ף�����\n"NOR,me);

        environment(me)->set("short","����");
        environment(me)->set("long","�����һ�ж��Ѿ����ˣ�����ով���һ���ƽ٣���������ʬ�嶼��������ֻ\n�ܿ���һƬ�ڽ�֮�к�����Щ�ʺ���̵ĺۼ�������\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","��ɢ����Ůը������Ƭ��");
		me->add_temp("block_msg/all",-1);
		me->die();	
		return 1;
	}
	// ��һ�������ˡ�����������

	switch (i)
	{
	case 1:
		who=p2;  // ��������
		me=p1;	// �����յ�

		tell_object(who,"ˮ�������˹�����\n"CYN"ˮ��������Զ��"+me->name()+"�ı�Ӱ������ĺ���һ����\n"NOR);
		tell_object(who,HIG"\nˮ�����ӻ���ȡ��һ����������С�ɰ����������֡�\n"NOR);
		tell_object(who,HIY"\n��Ҷ��͸�µ�΢����ҫ�У�����Լ���Կ���С�ɰ���"NOR);
		tell_object(who,HIY"\n�÷����Ľ��ߺ���Ƭ����һ��ĵ����������"NOR);
		tell_object(who,HIY"\nû�����ɵģ���ͻȻ����һ��������\n"NOR);
		tell_object(who,HIW"\nˮ��������İ���һ�ºɰ����������ֱ׷"+me->name()+"��ȥ��"NOR);
		tell_object(who,HIW"\n�漴����һƬ˸Ŀ��ѩ�ף��·�һǧ��̫���Ĺ�����"NOR);
		tell_object(who,HIW"\n�̵���һ˲�侹�������۾���\n"NOR);

		tell_object(me,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		message_vision(HIY"\n��ö���Ž���С������$N����бб���˹���������"NOR,me);
		message_vision(HIY"\n��Ⲣû��׷���㣬���������˹սǵĴ�ʯͷ�ϣ�\n"NOR,me);
		message_vision(HIW"\nһ��˸Ŀ�������ӹ��������ţ�ࣣ���һ����������\n�����죬�·����˼����ǵ��ᴥ���㻹û�з�Ӧ����\n����������ʲô����ǰ��ֻʣһƬããѩ�ף�����\n\n"NOR,me);

		tell_object(who,YEL"\n�Һ���վ�ú�Զ������û�б��ɼ��������Ƭ���У�"NOR);
		tell_object(who,YEL"\n����һɲ�Ƿ������£���һ�����޷����ǣ���Ϊ����"NOR);
		tell_object(who,YEL"\n��һɲ��������ڹ��Ź�ǰת��һȦ��"NOR);
		tell_object(who,YEL"\n���շ���������������ɼ�����ĺ�����Ƭ�����ڶ�"NOR);
		tell_object(who,YEL"\n�Ѿ����£��㾱�ϵ��亹��ȴ��û��Ǭ��\n\n"NOR);

		tell_object(me,YEL"�Һ���վ�ú�Զ������û�б��ɼ��������Ƭ���У�"NOR);
		tell_object(me,YEL"\n����һɲ�Ƿ������£���һ�����޷����ǣ���Ϊ����"NOR);
		tell_object(me,YEL"\n��һɲ��������ڹ��Ź�ǰת��һȦ��\n"NOR);
		tell_object(me,YEL"\n���շ���������������ɼ�����ĺ�����Ƭ�����ڶ�"NOR);
		tell_object(me,YEL"\n�Ѿ����£��㾱�ϵ��亹��ȴ��û��Ǭ��\n\n"NOR);

		tell_object(who,CYN"ˮ����̾�˿��������������˻�ȥ��\n"NOR);

		if (!room=find_object(__DIR__"path7"))
			room=load_object(__DIR__"path7");

		room->set("short","����");
		room->set("long","�����һ�ж��Ѿ����ˣ�����ով���һ���ƽ٣���������ʬ�嶼��������ֻ\n�ܿ���һƬ�ڽ�֮�к�����Щ�ʺ���̵ĺۼ�������\n");


	data = ([
		"name":		"��ɽ�ļ�",
		"target":	me,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	

	data = ([
		"name":		"��ɽ�ļ�",
		"target":	who,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	
		tell_object(me,WHT"\n���е��̳���ת���£�һ��һ���մȾ�������ϡ�\n"NOR);
		tell_object(who,WHT"\n���е��̳���ת���£�һ��һ���մȾ�������ϡ�\n"NOR);


		return 1;
		break;
	case 2:
		who=p1;	// �����յ�		
		me=p2;

		tell_object(who,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		tell_object(who,HIY"\n��Զ��ϸ΢���������һ����û��"HIW"�漴������һƬ˸"NOR);
		tell_object(who,HIW"\nĿ��ѩ�ף��·�һǧ��̫���Ĺ������̵���һ˲�侹"NOR);
		tell_object(who,HIW"\n�������۾���\n"NOR);

		tell_object(me,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		message_vision(HIY"\n��ö���Ž���С������$N����бб���˹���������\n\n"NOR,me);
		message_vision(HIW"һ��˸Ŀ�������ӹ��������ţ�ࣣ���һ����������\n�����죬�·����˼����ǵ��ᴥ���㻹û�з�Ӧ����\n����������ʲô����ǰ��ֻʣһƬããѩ�ף�����\n"NOR,me);

        environment(me)->set("short","����");
        environment(me)->set("long","�����һ�ж��Ѿ����ˣ�����ով���һ���ƽ٣���������ʬ�嶼��������ֻ\n�ܿ���һƬ�ڽ�֮�к�����Щ�ʺ���̵ĺۼ�������\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","��ɢ����Ůը������Ƭ��");
		me->add_temp("block_msg/all",-1);
		me->die();	

		tell_object(who,YEL"\n�Һ���վ�ú�Զ������û�б��ɼ��������Ƭ���У�"NOR);
		tell_object(who,YEL"\n����һɲ�Ƿ������£���һ�����޷����ǣ���Ϊ����"NOR);
		tell_object(who,YEL"\n��һɲ��������ڹ��Ź�ǰת��һȦ��"NOR);
		tell_object(who,YEL"\n���շ���������������ɼ�����ĺ�����Ƭ�����ڶ�"NOR);
		tell_object(who,YEL"\n�Ѿ����£��㾱�ϵ��亹��ȴ��û��Ǭ��\n\n"NOR);
	data = ([
		"name":		"��ɽ�ļ�",
		"target":	who,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	

		tell_object(who,WHT"\n���е��̳���ת���£�һ��һ���մȾ�������ϡ�\n"NOR);

		return 1;

		break;
	case 3:
		who=p1;	
		me=p2;

		tell_object(me,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		tell_object(who,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		message_vision(HIY"\n��ö���Ž���С������$N����бб���˹���������\n\n"NOR,me);
		message_vision(HIW"һ��˸Ŀ�������ӹ��������ţ�ࣣ���һ����������\n�����죬�·����˼����ǵ��ᴥ���㻹û�з�Ӧ����\n����������ʲô����ǰ��ֻʣһƬããѩ�ף�����\n"NOR,me);

        environment(me)->set("short","����");
        environment(me)->set("long","�����һ�ж��Ѿ����ˣ�����ով���һ���ƽ٣���������ʬ�嶼��������ֻ\n�ܿ���һƬ�ڽ�֮�к�����Щ�ʺ���̵ĺۼ�������\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","��ɢ����Ůը������Ƭ��");
		me->add_temp("block_msg/all",-1);
		me->die();	

		who->add_temp("block_msg/all",1);
		who->delete("tiwhor/lifesave");	// �仨��ˮһ��ȥ:p
		who->move("/obj/void");
		who->set_temp("last_damage_from","��ɢ����Ůը������Ƭ��");
		who->add_temp("block_msg/all",-1);
		who->die();	


		return 1;

		break;
	case 4:
		who=p1;	// ��������
		me=p2;

		tell_object(who,"ˮ�������˹�����\n"CYN"ˮ��������Զ��"+me->name()+"�ı�Ӱ������ĺ���һ����\n"NOR);
		tell_object(who,HIG"\nˮ�����ӻ���ȡ��һ����������С�ɰ����������֡�\n"NOR);
		tell_object(who,HIY"\n��Ҷ��͸�µ�΢����ҫ�У�����Լ���Կ���С�ɰ���"NOR);
		tell_object(who,HIY"\n�÷����Ľ��ߺ���Ƭ����һ��ĵ����������"NOR);
		tell_object(who,HIY"\nû�����ɵģ���ͻȻ����һ��������\n"NOR);
		tell_object(who,HIW"\nˮ��������İ���һ�ºɰ����������ֱ׷"+me->name()+"��ȥ��"NOR);
		tell_object(who,HIW"\n�漴����һƬ˸Ŀ��ѩ�ף��·�һǧ��̫���Ĺ�����"NOR);
		tell_object(who,HIW"\n�̵���һ˲�侹�������۾���\n"NOR);

		tell_object(me,HIY"\nû�����ɵģ���ͻȻ������ͷһ�䣬������ȥ��ֻ��"NOR);
		message_vision(HIY"\n��ö���Ž���С������$N����бб���˹���������\n\n"NOR,me);
		message_vision(HIW"һ��˸Ŀ�������ӹ��������ţ�ࣣ���һ����������\n�����죬�·����˼����ǵ��ᴥ���㻹û�з�Ӧ����\n����������ʲô����ǰ��ֻʣһƬããѩ�ף�����\n"NOR,me);

        environment(me)->set("short","����");
        environment(me)->set("long","�����һ�ж��Ѿ����ˣ�����ով���һ���ƽ٣���������ʬ�嶼��������ֻ\n�ܿ���һƬ�ڽ�֮�к�����Щ�ʺ���̵ĺۼ�������\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","��ɢ����Ůը������Ƭ��");
		me->add_temp("block_msg/all",-1);
		me->die();	

		tell_object(who,YEL"\n�Һ���վ�ú�Զ������û�б��ɼ��������Ƭ���У�"NOR);
		tell_object(who,YEL"\n����һɲ�Ƿ������£���һ�����޷����ǣ���Ϊ����"NOR);
		tell_object(who,YEL"\n��һɲ��������ڹ��Ź�ǰת��һȦ��"NOR);
		tell_object(who,YEL"\n���շ���������������ɼ�����ĺ�����Ƭ�����ڶ�"NOR);
		tell_object(who,YEL"\n�Ѿ����£��㾱�ϵ��亹��ȴ��û��Ǭ��\n\n"NOR);

		tell_object(who,CYN"ˮ����̾�˿��������������˻�ȥ��\n"NOR);

		tell_object(who,WHT"\n���е��̳���ת���£�һ��һ���մȾ�������ϡ�\n"NOR);

	data = ([
		"name":		"��ɽ�ļ�",
		"target":	who,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	

		return 1;
		break;
	}
	
	
	return 1;
}


int do_ics(object who,int i)
{
	object who2;
	if (query("p1") == who)
		who2=query("p2");
	else
		who2=query("p1");

	if (!who || !who2)
		do_instantsmash(who,who2,query("ob"),3);

	switch (i)
	{
	case 1:	// ����һ�˵����յ�
		
		if (who2->query_temp("condition_type") == NOR CYN" <��������>"NOR)
			// ��һ�˲���������������ɡ�
			do_instantsmash(who,who2,query("ob"),1);
		else
			// ��һ�˵�ù��..
			do_instantsmash(who,who2,query("ob"),2);
		break;
	case 2:	// ����һ����ǰ��ȥ��û���˲�������
		// һ��ù...
		do_instantsmash(who,who2,query("ob"),3);
		break;
	}	
}

int do_killob(object p1,object p2,object ob)
{
	if (!ob)
		return 0;
	if (!p1 && !p2)	// ��������
		return 0;
	
	if (query("interrupted"))
		return 0;

	if (p1 && p1->query_temp("condition_type") == NOR CYN" <��������>"NOR)
	{	// p1��������p2��ù��
		do_instantsmash(p1,p2,query("ob"),4);
		return 1;
	}	

	if (p2 && p2->query_temp("condition_type") == NOR CYN" <��������>"NOR)
	{	// p2��������p1��ù��
		do_instantsmash(p2,p1,query("ob"),4);
		return 1;
	}	

	// û���˲�������
	do_instantsmash(p1,p2,query("ob"),3);
	return 1;
}

int do_opengate(object p1,object p2,object ob)
{
	object env = this_object(),room;
	if (!p1 || !p2)
		return 0;
	if (environment(p2) != env)
		return 0;
	if (environment(p1) != env)
		return 0;
	if (p1->query("kee") < 1)
		return 0;
	if (p2->query("kee") < 1)
		return 0;
	message_vision(CYN"\n$N��׼��϶������$n��ˮ������ߴܹ����˽�����֮�У�\n\n"NOR,p1,p2);
	if (!room=find_object(__DIR__"path1"))
		room=load_object(__DIR__"path1");
	p1->move(room);
	p2->move(room);
	message_vision(CYN"\n$n����ɻ�һ����ʯ���ϣ�ʯ�񻺻��ƻ�ԭλ����ס�˰�������ڡ�\n\n"NOR,p1,p2);
	room->delete("exits/north");
	set("p1",p1);
	set("p2",p2);
	set("ob",ob);
	message_vision(RED"(��ʱ��ס��ʯ�����ƺ��������赲Ǭ��������ã����Ǿ����뿪����ɡ�)\n"NOR,p1,p2);
	call_out("do_killob",300,p1,p2,ob);
	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
