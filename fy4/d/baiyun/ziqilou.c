//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "��������¥");
    set("long", @LONG
�˼��ǰ��Ƴ��д������¥�һ�����������Ļ������������ȣ������ü�����
���¡�¥�ڵ�����������ڻԻͣ�����������ˣ��޲�������䣬Զ��ǧ������Ͻ�
�Ǵ��Ҳ������ˡ���¥�ڰ���������챦����������Ĺ�����ȸ���������Ŀ��
LONG
    );
    set("exits",
      ([
	"west" : __DIR__"skystreet",
	"up" : __DIR__"ziqilou2",
      ]));
    set("objects",
      ([
	__DIR__"npc/yexingshi" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-130);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
