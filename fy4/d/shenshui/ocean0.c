// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ã�ޱ߼ʵ�[33m��ˮ[32m���������κεĴ�ֻ��·�أ��㱻���ޱ��޼ʵĺ�ˮ��
Χ�ţ����Ų��˶��𸡣���ɬ�ĺ�ˮ��ʱ�ع�����Ŀ��У��㲻�ɵظе����Լ���
��С����֪���ж����������ᡣ
LONG
        );
   
   set("item_desc", ([
   		"��ˮ":		"��Ȼ���˺���,����Ӧ��������Ӿ�ˣ�swim��\n",
   	]));	
   		
   set("objects", ([
   ]) );   

	set("coor/x",1100);
	set("coor/y",-12640);
	set("coor/z",-60);
   setup();
}

void init()
{
   add_action("do_swim", "swim");
}

int do_swim(string arg)
{
   object me, room;
   int kar, k;
  
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("����ս���У�\n");
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɡ�\n");
   
   me->start_busy(2);
   
   message_vision("\n$N������ǰ��ȥ!\n", me);
   
      tell_object(me, "ԶԶ�����ƺ�������һƬ½�أ����þ����е��������Ƕ���ȥ��\n");
      message_vision("$N����ʪ���ܵ������˰���!\n\n", me);
      room = find_object(AREA_EASTCOAST"seaside");
      if(!objectp(room)) room = load_object(AREA_EASTCOAST"seaside");
      me->move(room);
      message("vision", me->name()+"ʪ���ܵشӺ�������������\n", environment(me), me);
      return 1;
}
