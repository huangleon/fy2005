//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "����������¥");
    set("long", @LONG
�����һ¥��Ӻ�ݻ�������ڻԻͣ���¥ȴ������嵭���ţ����涼�ǳ����Ĵ�
����¥�����������������̴ľ�㼸������ڵ���һ�����٣����׷���һ�������ӣ�
�������һ��ˮī����Ŀ�ݣ����������һ���ᡣ
LONG
    );
    set("exits",
      ([
	"down" : __DIR__"ziqilou",
      ]));
    set("objects",
      ([
	//       __DIR__"npc/yexingshi" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-130);
    set("coor/z",40);
    setup();
    replace_program(ROOM);
}
