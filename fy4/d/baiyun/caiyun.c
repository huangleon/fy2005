//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "�Ƽ�跻");
    set("long", @LONG
ֻ�ڴ�ɽ�У����֪�����Ƽ�跻λ�ڰ��Ƴ�����ƽʱ���в��޶��ٿ��ˣ���
�ǽ���ͻȻ��֪�Ǻ�ԭ�򣬰��Ƶ�����˲��ٽ����ϸ��Ÿ��ɵ�ɮ���������������֡�
����������е��Ƽ�跻һʱ������˸�ʽ������������۸߰����ݣ��������
�ƺ��������Ƶ��󶼱�ɸ��Ų���������
LONG
    );
    set("exits",
      ([
	"north" : __DIR__"skystreet3",
      ]));
    set("objects",
      ([        __DIR__"npc/qianqian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-170);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
