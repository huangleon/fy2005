//XXDER
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ��[33m����[32m����ڳ����ϣ���������������ˮ�档ټ���һ����ȴֻ�ڰ�������
��Сһ���������󲿷ֵ���Ӱ��Ͷ���˳����ϣ�����ɢ��ط��ż�����״���ص�̫
��ʯ��һ��С·�������Ƶ��˳�������һ�档
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "southeast" : __DIR__"backdoor",
   "southwest" : __DIR__"pond",
   ]));

   set("item_desc", ([
      "tree" : "��������������ˮ���ϣ�������ˮ̫���������ϳ�������̦��\n",
      "����" : "��������������ˮ���ϣ�������ˮ̫���������ϳ�������̦��\n",
   ]) );
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
   set("outdoors", "qingping");
}

void init()
{
   add_action("do_climb", "climb");
}

int do_climb(string arg)
{
   object me, room;
   int llvl;
   
   me = this_player();
   if(!arg || arg != "����" && arg != "tree") 
      return notify_fail("��Ҫ��ʲô ? \n");
   llvl = (int)me->query("kar");
   if(random(100)<llvl) {
      	message_vision("\n\n$N������������������ȥ�������˺��ں�����������ϡ�\n", me);
      	room = find_object(__DIR__"liutree"); 
      	if(!objectp(room)) room=load_object(__DIR__"liutree");
      	me->move(room);
      	message("vision", me->name()+"�����������������������������������ϡ�\n", environment(me),me);
   }
   else{
      message_vision("\n\n$N��������С���������ǰ����������


ͻȻ����һ������ͨһ��������ˮ�\n\n", me);
      room = find_object(__DIR__"pond1"); 
      if(!objectp(room)) room=load_object(__DIR__"pond1");
      me->move(room);
      message("vision",me->name()+"��ͨһ�����������������\n",environment(me), me);
   }
   return 1;
}
