//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���ƻ�ջ");
    set("long", @LONG
�������϶�һ�޶���һ�һ�ջ����Ϊ���������϶�һ�޶�����Ư�����ϰ��Ҳ
�ж�һ�޶����ϰ壬��ͣ����ͣ���������⣬����Ϊ������ʲô���⣬��ʲô�꣬��
������ʴ����ʱ����������ð����գ����ο���Ҳ��û�����ϰ�ı�Ǯ�������и�
�����ϰ���ϰ��������ͣͨ��ֻ�����ҵ������ϴ�����ö��ˣ����ϵ�����
ȻҲ���ˣ����ֵ��˿��������Ǻ��и��������ӣ�������ͣ�����ƺ����Ǹ����ϰ��
������Ȼ������Ը�⡣
LONG
    );
    set("exits",
      ([
	"south" : __DIR__"skystreet3",
	"north" : __DIR__"fuyunneishi",
      ]));
    set("objects",
      ([
	__DIR__"npc/beautyboss" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-150);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
