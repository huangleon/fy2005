//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���ƻ�Ժ");
    set("long", @LONG
���Ƶ������Ƴ�ͨ�������黭�������ſ͡���ʹ�ڰ��������У���Ȼ�Ի�������
������ѧ��ΪҲ��ǳ����ȴ��ð����ɺ����������۰���һ����������ڻ���ɰ�
��С������һ���棬Ҳ����Ϊ����Ļ�����Ϊ�߳�������࣬���Ƴ���Ҷ�³Ǻ�����
��ר����һ����Ϊ�����ڰ��Ƶ��ӵĳ������������Ӵ˵�̫�ף������Ҷ�³ǲ�����
�����ᵽ���⵺��С�ܡ��˴�Ҳ����Ҷ�³ǳ��������ɴ��ɮ��Ȼ���֡�
LONG
    );
    set("exits",
      ([
	"east" : __DIR__"skystreet2",
      ]));
    set("objects",
      ([        __DIR__"npc/juran" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
