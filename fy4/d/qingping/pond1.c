//XXDER
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����ˮ���Ǻ���ո�û������ز���С��СϺ����Ĵ��������޶ã���Ȼ
�����ȱ߿��ֵش��󣬿���ˮ�е��Ӳ�ȴ�����ز�ס�����˫�ȣ��ƺ�����������
������֮�ͣ�ʹ���޷��ƶ���֡���ϣ�������������ȥ��
LONG
        );
   set("outdoors", "qingping");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",-10);
   setup();
}
 
void init()
{
   add_action("do_up", "go");
}

int do_up(string arg)
{
   object me, room;
	
   if (arg != "up")	return 0;
   me = this_player();
   me->add_temp("up_time",1);
   
   if((int) me->query_temp("up_time") <= (2+random(8))) {
      message_vision("$N�����������ˮ�ݣ���ȴ��Խ��Խ���ˣ�����\n",me);
      tell_object(me, "��о���һ�ɺܴ�������ڰ������³��� \n");
      me->receive_damage("kee",10+random(100));
      me->set_temp("last_damage_from","����ƽ�ĳ����ﱻˮ������ˡ�\n");
      return 1;
   }
   else {
      tell_object(me, "��Ȼ��һ�ɺܴ����������������ˮ�С� \n");
      room = find_object(__DIR__"underwater");
      if(!objectp(room)) room=load_object(__DIR__"underwater");
      me->move(room);
      return 1;
   }
   
   return 0;
}
