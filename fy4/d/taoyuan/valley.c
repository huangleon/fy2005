inherit ROOM;

void create()

{

        set("short", "ɽ��");
        set("long", @LONG
���ֵ��˴˴��𽥱��ϡ����������ǰ��Ȼ����һ��ǧ����䡢�����Ե�ɽ
�壬Χ��һ���Ĺȣ�����һ����̶��Ȫˮ�ӷ�䱼�����£�����й��ֱ����̶��
��ֻ��β�͵�Ұ�ã�����̶�����еĺ�ˮ���˴���������ʪ�������ķΣ�����ȴ
�������κ����Եĳ�·��
LONG
        );

	set("objects", ([
	__DIR__"npc/rabbit1": 3,
        ]) );

        set("outdoors","taoyuan"); 
	set("coor/x",-50);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
void init()
{
   add_action("do_west", "west");
   add_action("do_catch", "catch");
   add_action("do_around", "around");
}



int do_around(string arg)

{

   object me, room;
   int i;
   string *rooms = ({"valley", "valley1", "valley2", "valley3"});
   i = random(4);
   me = this_player();
   tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n");
   room = find_object(__DIR__ + rooms[i]);
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]);
   me->move(room);
   return 1;
}



int do_catch(string arg)

{
   object rabbit, me, room;
   me = this_player();
   if(!arg || arg != "Ұ��" && arg != "rabbit" ) return 0;
   rabbit = present("rabbit", this_object());
   if(!objectp(rabbit)) return 0;
   switch ( random (7)) {
   case 0:
      message_vision("$N��ǰһ�ˣ�Ұ������һ����$N���˸��ա� \n", me); 
      break;
   case 1:
      message_vision("$N����һ�ˣ�Ұ������һ����$N���˸��ա� \n", me); 
      break;
   case 2:
      message_vision("$N����һ�� , Ұ������һ����$N���˸��ա�\n", me); 
      break;
   case 3:
      message_vision("$N�����ҵ������ظ���Ұ�ã�����һת�۾Ͳ����ˣ�����\n", me);
   	break;
   case 4:
      message_vision("$N��������Ұ�� , Ұ�����Ա�һ�ܶ㿪���㣬$N���Ʋ�סˤ�˸�����ࡣ  \n", me);
   	break;
   case 5:
      message_vision("$N������ŵس�Ұ������ȥ����Ӻ���ץס����Ұ�û������ǰһ�壬$Nû�ɹ���\n", me);
	break;
   case 6:
      message_vision("$N����ǰһ�� , Ұ����ǰһ�� , ��$N�Ŀ��·ɿ�����˹�ȥ�� \n", me); 
      message_vision("$N��ͷ����Ұ�����ܵķ���׷ȥ.... \n", me); 
      message_vision("\nҰ����ת��ת��ٿ��һ�²�������Ӱ��\n\n", me); 
      message("vision", me->name() + "��������Ұ��ת�۲�������Ӱ��\n", environment(me), me);
      room = find_object(__DIR__"fenghuo");
	      if(!objectp(room)) room=load_object(__DIR__"fenghuo");
      me->move(room);
//    destruct(rabbit);
      break;
   }
   return 1;
}



int do_west(string arg)

{
        object me;
        object room;
        me = this_player();
        message_vision("$N�����ߵ�������ȥ . \n", me);
        room = load_object(__DIR__"taolin2");
        if(room) me->move(room);
        return 1;
}
