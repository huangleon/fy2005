//XXDER
inherit ROOM;
void create()
{
        set("short", "Ժǽ");
        set("long", @LONG
Ժǽ�ܸߣ��Ա���һ�Ÿߴ�Ļ�����ï�ܵ���֦�ڵ���������ߣ��㿴����Ժ
�ڵ������Ժ��������һƬ���֣���һƬ����Ҳ�����������ߣ��������ǻ��ߵ�
Ұ�ݺ���ʯ���ɼ�������������߶���
LONG
        );
   set("outdoors", "qingping");
	set("coor/x",-15);
	set("coor/y",0);
	set("coor/z",10);
   setup();
}

void init()
{
   add_action("do_jump", "jump");
}

int do_jump(string arg)
{
   object me, room;

   me = this_player();
   if(!arg || arg != "down" ) return 0;
   message_vision("$N����Ծ����ƮƮ���䵽��Ժ�ڵ��ϡ�\n\n", me);
   room = find_object(__DIR__"garden"); 
   if(!objectp(room)) room=load_object(__DIR__"garden");
   me->move(room);
   message("vision", me->name()+"�ƺ������������ƮƮ���䵽�˵��ϡ�\n", environment(me), me); 
   return 1;
}
