//Sinny@fengyun 2003 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
    set("short", "��");
    set("long", @LONG
����¥�������ڣ�˭Ҳ�޷��������֮�о�Ȼ�����һ����ֱ���ĳ���������
�Ե��Ų���ĳ����ƣ������䲻��������Ҳ�ɱ��·���ƺ���������ɽ������Ȼ��Ѩ
������ɣ��˹����䴦������խ����ʱȴ��Ȼ������ֻ�����н��ͣ����г�������ˮ
֮��������������ö��������������ǰ���ƺ���Щ��ƹ����������
LONG
    );
    set("exits", 
      ([ 
	"north" : __DIR__"changlang2",
	"south" : __DIR__"baiyunguan",
      ]));
    set("objects", 
      ([ 
      ]));
    set("indoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-270);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
