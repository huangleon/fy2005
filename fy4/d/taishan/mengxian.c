// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�س����򶫱�ȥ���㵽�����裬һ·����Ʈ����ɽ�����󣬼е���ľ���ǰ���
�ɰأ������Բԣ�Զ��������ɽ�������������������磬��������ƮƮ���ɣ��ഫ
�������ƻ���ɽ����С���μ���ϼԪ�������ڣ�ɽ��������ССһ���裬ʮ�־�
�£�����Ҳ���������ܹ��ɽ�֮����Զ����ľԽ��Խ�ܣ���������������կ�ˡ�
LONG
  );
  set("exits",([
	"east" : AREA_OLDPINE"npath1",
	"westdown" : __DIR__"chaoyang",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",100);
	setup();
  	replace_program(ROOM);
}

 
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

