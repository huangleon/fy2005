

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "�����"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

�������ŵģ������ڹ���ģ���ȴ���ձ黯�ģ�ƽ�񻯵ġ�
�йؽ������룬�����Ǵ�͢�e������ɽ�e���ڰ��Ƽ䡣
��ȴ�Ǻ����������ϢϢ��صġ�
��ֵ��ǣ������ǵ���Ŀ�У���Զ�Ƚ����п�����Ҹ��׺���Ұ�������¡���

LONG);
        set("exits", ([

  "down" : __DIR__"cloud"+(query("floor")-1),
  "up" : __DIR__"cloud"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-50);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
