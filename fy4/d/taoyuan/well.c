inherit ROOM;
void create()
{
        set("short", "ˮ����");
        set("long", @LONG
ˮ����������ľ�ˮ�������ͷ�����飬һֻ����һ�����������ˮͰһ��
һ������ˮ�е�����һ��������ͷ����������������΢�����㶼��֪������û��
�����Ļ��ᣮ����
LONG
        );
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",-10);
        setup();
}

void init()
{
   add_action("do_climb", "climb");
   if(interactive(this_player()))
   call_out("do_flush",60,this_player());
}

int do_climb(string arg)
{
   object me, room;

   me = this_player();
   if(me->is_busy())
	return notify_fail("������û�գ�\n");
   switch (random(3)) {
   case 0:
      message_vision("$N�ֽŲ��õ���������������һ�룬һʧ����ˤ��������\n", me);
      me->receive_damage("gin",20);
	  me->set_temp("last_damage_from","����Դ�ľ��������ˡ�\n");
	  me->start_busy(5);
      break;
   case 1:
      message_vision("$N�ֽŲ��õ����������ۿ��쵽�����ˣ����һʧ����ˤ��������\n", me);
      me->receive_damage("gin",40);
		me->set_temp("last_damage_from","����Դ�ľ��������ˡ�\n");
		me->start_busy(5);
      break;
   case 2:
      if(!arg || (arg != "��" && arg != "up" && arg!= "well")) return 0;
      room = find_object(__DIR__"cyard1");
      if(!objectp(room)) room=load_object(__DIR__"cyard1");
      me->move(room);
      message_vision("$N����ʪ���ܵش�ˮ��������������\n", me);
      break;
   }
   return 1;
}

void do_flush(object me)
{
   object room;

   if(!me || environment(me) != this_object())
   return;
   tell_object(me,"\n��ͻȻ���������ˮ��Ȼ��������\n\n");
   tell_object(me,"ˮ�����������Ӿ��׵�һ��������ӿ��������\n");
   tell_object(me,"������һƬ��ȫ�ĺڰ�֮�У����г����˿־壮����\n\n");
   room = find_object(__DIR__"tunnel");
   if(!objectp(room)) room= load_object(__DIR__"tunnel");
   me->move(room);
}


