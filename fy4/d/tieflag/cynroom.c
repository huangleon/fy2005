#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",CYN "����"NOR);
  set("long",@LONG
����ǽ��һ���ɽˮ������ɽ��ˮ�������������Ϊ֮һ�����ڶ�����ɫ��
��ÿɰ�����ô��棡
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/cyngirl" : 1,
       ]) );
    set("item_desc",([
    	"picture": "������ƺ������ƿ�(open)��\n",
        "��": "������ƺ������ƿ�(open)��\n",
        "ɽˮ��": "������ƺ������ƿ�(open)��\n",
        "hua": "������ƺ������ƿ�(open)��\n",

    ]) );
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
 }
void init()
{
	add_action("do_open","open");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "picture" || arg == "��" || arg == "hua" || arg == "ɽˮ��")
        {
        me = this_player();
        message_vision("$N��������ǽ�ϵ�ɽˮ����¶���˺���İ��š�\n", me);
        tell_object(me,"�㲻��������ϲ�����������ˣ���һ�¾��ҵ��ˡ���\n");
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"gu5");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("�㲻���Դ�"+arg+"\n");
                return 1;                     }
}
void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"ɽˮ�����˻���������ס�˰��š�\n",
                this_object() );
                delete("exits/south");
}

