// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ܶ�");
        set("long", @LONG
���߳�������ͷ����Լ��Ѿ���ʧ�˷����ƺ�����ԭ�ش�ת��ʯ������Ƕ��
���СС�����飬����ǧ�˰�̬������ɫ������ʯ������Ӱ���·������԰�Ĺ�
�ʣ���������ֻ���۾��ڿ����㣬��֪��ǧ�꼸�����ˮ��˳����ʯ�丵��䡣
LONG
        );
   set("exits", ([ 
      "north": __DIR__"rongdong1",
      "south": __DIR__"rongdong1",
      "east": __DIR__"rongdong1",
      "west": __DIR__"rongdong1",
   ]));

   set("item_desc", ([
      "stone": "��ǧ�ٸ�����ʯ�У���ע�⵽����һ���ƺ��������ùⲻ���֡�\n",
      "����ʯ": "��ǧ�ٸ�����ʯ�У���ע�⵽����һ���ƺ��������ùⲻ���֡�\n",
   ]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}

void init()
{
   add_action("do_look", "look");
   add_action("do_southeast", "go");
   add_action("do_touch", "touch");
}

int do_touch(string arg)
{
   object me, room;

   me = this_player();
   if (!arg || (arg != "stone" && arg != "����ʯ")) return 0;
   if (me->is_fighting()) return notify_fail("�㹻��������ʯ��\n");
   message_vision("\n\n$N������һ������ʯ�ϰ�ȥ��\n", me);
   tell_object(me, "��ֻ���ý���һ�գ���������׹ȥ���������㷢��һ����С�\n\n");
   message("vision", "ֻ��һ����У�����.......��..." + me->name()+"��ʧȥ����Ӱ��\n",environment(me), me);
   room = find_object(__DIR__"migong");
   if(!objectp(room)) room = load_object(__DIR__"migong");
   me->move(room);
   message("vision", "ֻ����ѽһ����"+me->name()+"����������������\n",environment(me), me);
   return 1;
}

int do_look(string arg)
{
   object me;
   int clvl;

   me = this_player();
   if (!arg || (arg != "pearl" && arg != "����")) return 0;
   clvl = (int)me->query_cps();
   if (random(80) < clvl) {
      tell_object(me, "�㿴��ʯ�����м��������ƺ����һ��С��ͷ��������Ŷ��Ϸ���\n"); 
      me->set_temp("marks/southeast", 1);
   }
   else {
      tell_object(me, "������ʯ������ɸ������־��ͼ�����㿴�˼��۲�����������������\n");
      message("vision", me->name()+"��ʯ�������˼��ۣ�ˢ��һ��������������\n", environment(me),me);
      me->receive_damage("sen", random(100));
      me->set_temp("last_damage_from","����ˮ�ܶ�������Ϳ�����ˡ�\n");
   }
   return 1;
}

int do_southeast(string arg)
{
   	object me, room;

   	me = this_player();
   	if (arg == "southeast")
   	if(me->query_temp("marks/southeast")) {
      		tell_object(me, "�����Ϸ���ȥ��\n\n");
      		message("vision", me->name()+"���Ϸ���ȥ��������ʯ��ת�˼�ת��ʧȥ����Ӱ��\n", environment(me),me );
      		room = find_object(__DIR__"rongdong");
      		if(!objectp(room)) room=load_object(__DIR__"rongdong");
      		me->move(room);
      		return 1;
   	}
   	return 0;
}

