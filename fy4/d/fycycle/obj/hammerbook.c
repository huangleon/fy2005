inherit __DIR__"tutor";

void create()
{
        set_name("��������", ({ "iron statue","����", "statue" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "һ��ŭĿԲ�����뷢��ŵ�׳ʿ�����������׵����������������\n��ϸ��֮�£�������������ƺ���չʾ�˴��ķ�����\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "hammer");
 		set("teaching_limit", 400);
 	}
 	
 }
