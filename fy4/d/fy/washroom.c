#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "˽��ѧ��");
    set("long", @LONG
������ǰ��һ��ϴ�µ꣬����Ǯ�˽��·�������ϴ�ĵط����Դ�������ϰ���
ȥ�����Ժ���һ������ס�˽����������ĳ�һ��˽�ӣ�����Ϊ����̫�ң���û��
����ѧ�����ſ���һ����ľ�ƣ�������
LONG
    );
    set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"ecloud1",
      ]));

    set("objects", ([
	__DIR__"npc/taipo" : 1,
      ]) );
    set("coor/x",80);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}



void init(){
    add_action("do_look","look");
}


int do_look(string arg){
    string msg;

    if (arg == "sign" || arg == "ľ��"){
	msg = "
[0;1;37m����������������������������������������������������������������[0m
[0;1;31m		�칤������Ī��[0m
[0;1;37m����������������������������������������������������������������[0m
             
��˽�����������ĸ�����+,-,*,/,��()�����ʮ�ġ�

���磺	������ĸ����ǣ���,��,��,��. ����һ�����ڸ�����(answer)
	answer (9-2)*3+3
	��һ����ԵĽ���һ���ġ�
             
";
	//	if (stringp(this_object()->query("question")))
			msg = msg + WHT"		���ڵ�������" + query("question") + "\n"NOR;
		
		msg += "[0;1;37m����������������������������������������������������������������[0m\n";
		write(msg);
		return 1;
	}        	
	return 0;
}
