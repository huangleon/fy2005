#include <room.h>
#include <ansi.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "ɽ����");
        set("long", @LONG
��Ծ����ȣ���Ŀ�Ĺˣ�ֻ���ȵ׷�����ݣ�����ͬһ������Ļ�԰���ľ���
�ƣ������˱ǣ����Ǳ��ж��졣Ȼ����Ӱ�������Ĺ����ˣ�ֻ����ʮ���⣬һ����
��ɫ���������ſ�ɽ�����һ�ߵ����Ⱥ�����ȴ�ǹص�����ʵʵ����ˮ���롣
LONG
        );
	set("no_fly",1);
	set("no_fight",1);
	set("no_magic",1);
	set("exits",([
  		"north" : __DIR__"hall",
  		"south" : __DIR__"hall",
	]) );
    create_door("north","door", "������", "south", DOOR_CLOSED);
	set("item_desc", ([
		"north": "���Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n",
		"������": "���Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n",
		"����": "���Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n",
		"irongate": "���Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n",
		"iron gate": "���Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n",
		"����": "�����Ŵ˿��������ţ����Ƿ���ˮ�����򿪡�\n",
		"jadegate": "�����Ŵ˿��������ţ����Ƿ���ˮ�����򿪡�\n",
		"south": "�����Ŵ˿��������ţ����Ƿ���ˮ�����򿪡�\n",
		"jade gate": "�����Ŵ˿��������ţ����Ƿ���ˮ�����򿪡�\n",
		"gate": "�����Ŵ˿��������ţ����Ƿ���ˮ�����򿪣������Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n",
		"��": "�����Ŵ˿��������ţ����Ƿ���ˮ�����򿪣������Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n",
		"��": "����һ����û�м����ĵ���ɫС�������������˱Ƕ���(smell)��\n",
		"����": "����һ����û�м����ĵ���ɫС�������������˱Ƕ���(smell)��\n",
		"flower": "����һ����û�м����ĵ���ɫС�������������˱Ƕ���(smell)��\n",
	]) );

	set("coor/x",-40);
	set("coor/y",200);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	add_action("do_swing","smell");
	add_action("do_open","open");
}

int do_open(string arg){
	object me, ob, room;
	
	me = this_player();
	if(!arg || arg != "������" && arg != "����" && arg != "door" && arg != "gate"){
		return 0;
	} 
	tell_object(me, "���Ⱥ����Źص�����ʵʵ������һ˿��϶Ҳû�С�\n������޴����ִ򿪣�����\n", me);
	return 1;
}

int do_swing(string arg)
{
	object me = this_player(),env=this_object();
	int gin,kee,sen;
	mapping buff;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("��������æ��\n");
	message_vision("$N������ȥ�������ŵ���ɫ��С��������\n",me);
	tell_object(me,HIB"��ֻ����һ��ͷ��Ŀѣ��վ�����ȡ�\n"NOR);

		  gin = me->query("max_gin");
		  me->set("effgin", gin);
		  me->set("gin", gin);
		  kee = me->query("max_kee");
		  me->set("effkee", kee);
		  me->set("kee", kee);
		  sen = me->query("max_sen");
		  me->set("effsen", sen);
		  me->set("sen", sen);

		tell_object(me,HIR "\n�����ǰһ�ڣ�����ʲ��Ҳ��֪����....\n\n" NOR);
			me->add_temp("block_msg/all",1);

			buff =
			([
				"caster":me,
				"who":me,
				"type":"freeze",
				"att":"bless",
				"name":"��ɽ����ս�����껨",
				"buff1":"disable_inputs",
				"buff1_c":1,
				"buff2":"is_unconcious",
				"buff2_c":1,
				"buff3":"block_msg/all",
				"buff3_c":1,
				"disable_type":HIR " <���Բ���>"NOR,
				"time":20+random(20),
				"buff_msg":"\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n"NOR,
//				"disa_msg":HIY "\n�����������������֪��....\n\n" NOR,
				"disa_msg":"\n$N���������۾��������˹�����\n\n",
				"disa_type":1,
			]);
			ANNIE_D->buffup(buff);
			me->add_temp("block_msg/all",-1);
		return 1;
}
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
