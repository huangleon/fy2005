// Tie@fy3
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����������������̴ľ���ӣ��������ؤ�������һ�ڳ������µĵط�������
̫ʦ���ϵ����������Ƥ�����������Ű׻�Ƥ�棬�����Ǳ��Ϲ���ؤ����ʦү��
³���ͺ��߹��Ļ��񣬻���Ϊ�ǵ���ʲô����֮�ҡ�
LONG
  );
  	set("exits",([
        	 "south":__DIR__"gb1",
                 "north":__DIR__"private",
               ]));
        set("objects", ([
                __DIR__"npc/master4" : 1,
       	]) );
        set("coor/x",-20);
        set("coor/y",100);
        set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        
        if (REWARD_D->check_m_success(me,"���ȵ��"))	
        	return ::valid_leave(me,dir);
        
        if( dir == "north" && ob=present("master nangong", this_object()))
                return notify_fail("��������·��"+ob->name()+"��ס�� ��\n");
        return 1;
}
