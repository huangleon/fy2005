#include <room.h>
inherit ROOM;
void close_path();
void create()
{
  set("short","����");
  set("long",@LONG
��ľ�������ѱ���ͺ��������ķ������ȼ������о�������˫�ﳯĵ����ͼ
���ľ����Ͻ�������������˻��ɴ�����������һ����С�
LONG
  );
  set("exits",([
         "north":__DIR__"chanfang.c",
//         "south":__DIR__"zhaitang.c",
         "east" :__DIR__"houyuan.c"
               ]));
        set("item_desc", ([
                "����": "
                        �������ƺ���һľ�������������\n",
                "langlan": "
                        �������ƺ���һľ�������������\n"

        ]) );
          set("objects", ([
                __DIR__"npc/bigmonk" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
add_action("do_push","push");
}
int do_push(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "button" )
        {
        me = this_player();
        message_vision("$N������ľ��������ǰ���İ���������Ϣ�ػ����ˡ�\n", me);
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaitang");
        call_out("close_path", 5);
        }
        return 1;
        }
        else
        {
                write("��������"+arg+"��\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"����ǰ���İ���������Ϣ��ת�˻�������ס�����ϵ�·��\n",
                this_object() );
                delete("exits/south");
}

